#include <winsock2.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <InetSDK.h>
#include <iostream>

using namespace std;

#define BACKLOG 10							// how many pending connections queue will hold
#define MAXDATASIZE 100						// max number of bytes we can get at once
#define PORT 60000

//Declerations of usefull variables - I don;t know if it is a good idea to make these global perhaps there is a better way
int sockfd, new_fd, bytes_recv, bytes_sent;
char buf[MAXDATASIZE];
string ip;


int sendData (int sockfd, string input)
{
	int len = input.length();
	bytes_sent = send(sockfd, input.c_str(), len, 0);
	if ( bytes_sent == -1 ) 
    {
        printf("bytes_sent failed: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
	return 0;
}
int receiveData (int sockfd)
{
	//Here i am recieving bytes from connection new_fd, the 0 is for the flags, i don't know em so i put 0 
	bytes_recv=recv(sockfd, buf, MAXDATASIZE-1, 0);
	if (bytes_recv == -1) {
		printf("bytes_recv: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	return 0;
}


int startserver (int choice)
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
    
	if (choice == 1)
	{
		my_addr.sin_family = AF_INET;					// host byte order
		my_addr.sin_port = htons(PORT);				// short, network byte order, 0 will make it choose a random open port
		my_addr.sin_addr.s_addr = INADDR_ANY;			// auto-fill with my IP -- don't know so much as that i think it fills it with nothing like 0's

		memset(&(my_addr.sin_zero), '\0', 8);			// zero the rest of the struct

		// don't forget your error checking for these calls:
		printf("Binding Socket to a port ...\n");
		bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
		printf("Listening for a connection on the socket ...\n");
		listen(sockfd, BACKLOG);
		
		sin_size = sizeof(struct sockaddr_in);
	
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		printf("Someone connected, accepting connection ...\n");

		// useless crap starts ----------------------------useless crap starts-----------------------------------useless crap starts
		printf("OMG someone actually connected lets see now\n");
		printf("From ip: ");
		printf("%d", their_addr.sin_addr.S_un.S_un_b.s_b1);
		printf(".");
		printf("%d", their_addr.sin_addr.S_un.S_un_b.s_b2);
		printf(".");
		printf("%d", their_addr.sin_addr.S_un.S_un_b.s_b3);
		printf(".");
		printf("%d", their_addr.sin_addr.S_un.S_un_b.s_b4);

		printf("\n");
		printf("Connection is kept active on port: ");
		printf("%u", their_addr.sin_port);
		printf("\n");
		printf("Wasn't that a fun game?\n");
		// useless crap ends ------------------------------useless crap ends---------------------------------------useless crap ends
		printf("Closing old socket ...\n");
		closesocket(sockfd);
	}
	else if (choice == 2) //client code
	{
		dest_addr.sin_family = AF_INET;          // host byte order
		dest_addr.sin_port = htons(PORT);   // short, network byte order
		dest_addr.sin_addr.s_addr = inet_addr(ip.c_str());
		memset(&(dest_addr.sin_zero), '\0', 8);  // zero the rest of the struct

		if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr)) == -1) {
			printf("Connect FAILED %d\n", WSAGetLastError());
			return 1;
		}
	}

	return 0;
}

int main()
{
	string input;
	int choice, sequence=0;
	printf("Hello, please choose from the following choices\n 1 to host\n 2 to connect\n JUST ENTER THE NUMBER\n");
	cin >> choice;

	if (choice ==2)
	{
		printf("IP? \n");
		cin >> ip;
    }

	startserver(choice);
	//Code to send data
	//initial send
	if (choice ==1)
	{
		sendData(new_fd,"Hello new connection welcome to my server!\n");
	}
	// recieve wait send repeat always repeat, no real exit, muahahaha infinite loop
	while(1) {
		if (choice == 1)
		{
			receiveData (new_fd);
			buf[bytes_recv] = '\0';
			printf(buf);
			printf("\n");
			sequence++;
			if (sequence ==1) //for server
			{
				std::getline(std::cin, input); //for some reason on the first run of this loop for the server this line is run, but skipped or something, i can't for the life of me right now figure it out so i had to do this.
			}
			std::getline(std::cin, input);
			sendData(new_fd,input);
		}
		else if (choice == 2) //for client
		{			
			std::getline(std::cin, input);
			sendData(sockfd,input);
			sequence++;
			receiveData (sockfd);
			buf[bytes_recv] = '\0';
			printf(buf);
			printf("\n");
		}
	}
	return 0;
}
