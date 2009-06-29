#include <winsock2.h>
#include <string>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <InetSDK.h>
#include "globals.h"
#include "host.h"

using namespace std;

int bytes_recvServer, bytes_sentServer;
char bufServer[MAXDATASIZE];

int host::receiveDataServer (int sockfd)
{
	//Here i am recieving bytes from connection new_fd, the 0 is for the flags, i don't know em so i put 0 
	bytes_recvServer=recv(sockfd, bufServer, MAXDATASIZE-1, 0);
	if (bytes_recvServer == -1) {
		printf("Recieve Data Error: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	return bytes_recvServer;
}
int host::sendDataServer (int sockfd, string input)
{
	int len = input.length();
	bytes_sentServer = send(sockfd, input.c_str(), len, 0);
	if ( bytes_sentServer == -1 ) 
    {
        printf("Send Data Error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
	return 0;
}
int host::startserver ()
{
	int sin_size,sockfd, new_fd;
	struct sockaddr_in my_addr, their_addr;
	WSADATA wsaData;
	WORD wVersionRequested;
	wVersionRequested = MAKEWORD( 2, 2 );
	if ( WSAStartup( wVersionRequested, &wsaData ) != 0 ) 
	{                                  
		return 1;
	}
	sockfd = socket (PF_INET, SOCK_STREAM, 0);		// do some error checking! First, domain should be set to "PF_INET". Next, the type argument tells the kernel what kind of socket this is: SOCK_STREAM or SOCK_DGRAM. Finally, just set protocol to "0" to have socket() choose the correct protocol based on the type.
	my_addr.sin_family = AF_INET;					// host byte order
	my_addr.sin_port = htons(PORT);					// short, network byte order, 0 will make it choose a random open port
	my_addr.sin_addr.s_addr = INADDR_ANY;			// auto-fill with my IP -- don't know so much as that i think it fills it with nothing like 0's
	memset(&(my_addr.sin_zero), '\0', 8);			// zero the rest of the struct

	bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
	printf("Listening for a connection on the socket ...\n");
	listen(sockfd, BACKLOG);
	sin_size = sizeof(struct sockaddr_in);
	new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
	printf("Someone connected, accepting connection ...\n");
	closesocket(sockfd);
	return new_fd;
}
char* host::getBufServer()
{
	return  bufServer;
}
void host::clearBufServer()
{
	for (int i=0;i<bytes_recvServer;i++)
	{
		bufServer[i] = '\0';
	}
}