/**********************************************************
client.h
***********************************************************/
#ifndef CLIENT_H_
#define CLIENT_H_
using namespace std;

class client
{
	public:
		int clientConnect(string ip);
		int sendData (int sockfd, string input);
		int receiveData (int sockfd);
		char* getBuf();
		void clearBuf();
};

#endif CLIENT_H_