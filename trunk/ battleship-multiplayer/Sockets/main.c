// - to use winSock we need to include WS2_32.lib
// - sockets 1.1 is universally portable
// - all other socket libs (i.e. winSock) are wrappers with additional features

// We have to define this lean and mean macro
// because we don't want duplicate includes
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

void print_wsadata(WSADATA *data);
void print_addrinfo(ADDRINFOA *address);
int client(WSADATA *wsaData);

#define NODE_NAME       127.0.0.1
#define DEFAULT_BUFLEN  64
#define DEFAULT_PORT    27015

int main() 
{
    // Variable declaration ---------------------------------
    WSADATA wsaData;        // Contains info about WS implementation
    int wsInit;

    // The real program -------------------------------------

    // 1.) Initialize winsock
    wsInit = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (wsInit != 0)
    {
        printf("WS init failed with code: %d\n", wsInit);
        return 1;
    }
    else
    {
        printf("WS init!\n");
        print_wsadata(&wsaData);
    }

    // 2.) Invoke either the client or the server
    
    // The end of the program
    printf("Press enter key to continue ... \n");
    scanf("%d", wsInit);
    return 0;
}

void print_wsadata(WSADATA *data)
{
    // http://msdn2.microsoft.com/en-us/library/ms741563.aspx
    // - some fields are made of WORDS:
    //      WORD is 16-bit, WORD typdefs to unsigned short
    //      DWORD is 32-bit, DWORD typedefs to unsigned long
    //   so that you are compiler / architecture independent
    // This struct basically inits WS

    printf("Version WS callers use: %d\n", data->wVersion);
    printf("Highest Version avail: %d\n", data->wHighVersion);
    printf("Description: %s\n", data->szDescription);
    printf("Status: %s\n", data->szSystemStatus);
}

void print_addrinfo(ADDRINFOA *address)
{
    // http://msdn2.microsoft.com/en-us/library/ms737530.aspx
    // This struct holds host address information

    printf("The flags that are being used: %d\n", address->ai_flags);
    printf("The address family: %d", address->ai_family);
    printf("The type of socket: %d", address->ai_socktype);
    printf("The protocl being used: %d", address->ai_protocol);
    printf("The length of the buffer point to by ai_addr in bytes :%d", address->ai_addrlen);
    printf("The canonical name of host: %s", address->ai_canonname);    
    // address->ai_next     // pointer to sockaddr structure
    // address->ai_addr     // pointer to next structure in linked list
}

int client(WSADATA *wsaData)
{
    // Variable declaration ---------------------------------
    SOCKET ConnectSocket = INVALID_SOCKET;
    ADDRINFOA *result = NULL,
              *ptr = NULL,
              hints;

    char *sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int getAddrInit;
    int recvbuflen = DEFAULT_BUFLEN;

    // The real program -------------------------------------

    // Setup the "hint" address
    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    getAddrInit = getaddrinfo(NODE_NAME, DEFAULT_PORT, &hints, &result);
    if ( getAddrInit != 0 ) 
    {
        printf("getaddrinfo failed: %d\n", getAddrInit);
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    // iterate through the linked list of returned addresses
    for(ptr = result; ptr != NULL; ptr = ptr->ai_next) 
    {
        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) 
        {
            printf("Error at socket(): %ld\n", WSAGetLastError());
            freeaddrinfo(result);
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) 
        {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    // Send an initial buffer
    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
    if (iResult == SOCKET_ERROR) {
        printf("send failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    printf("Bytes Sent: %ld\n", iResult);

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
            printf("Bytes received: %d\n", iResult);
        else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed: %d\n", WSAGetLastError());

    } while( iResult > 0 );

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}
