#include <winsock2.h>
#include <string>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <InetSDK.h>
#include "globals.h"
#include "client.h"

using namespace std;

int bytes_recv, bytes_sent, sockfd;
char buf[MAXDATASIZE];

int client::receiveData (int sockfd)
{
	bytes_recv=recv(sockfd, buf, MAXDATASIZE-1, 0);
	if (bytes_recv == -1) {
		printf("Recieve Data Error: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	return bytes_recv;
}
int client::sendData (int sockfd, string input)
{
	int len = input.length();
	bytes_sent = send(sockfd, input.c_str(), len, 0);
	if ( bytes_sent == -1 ) 
    {
        printf("Send Data Error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
	return 0;
}
int client::clientConnect (string ip)
{
	int sin_size;
	struct sockaddr_in my_addr, their_addr, dest_addr;
	WSADATA wsaData;
	WORD wVersionRequested;

	wVersionRequested = MAKEWORD( 2, 2 );
	if ( WSAStartup( wVersionRequested, &wsaData ) != 0 ) 
	{
		printf("WSAStartup FAILED %d\n", WSAGetLastError());
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		return 1;
	}
	printf("Oppening Socket ...\n");
	sockfd = socket (PF_INET, SOCK_STREAM, 0);		// do some error checking! First, domain should be set to "PF_INET". Next, the type argument tells the kernel what kind of socket this is: SOCK_STREAM or SOCK_DGRAM. Finally, just set protocol to "0" to have socket() choose the correct protocol based on the type.

	dest_addr.sin_family = AF_INET;          // host byte order
	dest_addr.sin_port = htons(PORT);   // short, network byte order
	dest_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	memset(&(dest_addr.sin_zero), '\0', 8);  // zero the rest of the struct
	if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr)) == -1) 
	{
			printf("Connect FAILED %d\n", WSAGetLastError());
			return 1;
	}

	return sockfd;
}
char* client::getBuf()
{
	return  buf;
}
void client::clearBuf()
{
	for (int i=0;i<bytes_recv;i++)
	{
		buf[i] = '\0';
	}
}