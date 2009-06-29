/**********************************************************
host.h
***********************************************************/
#ifndef HOST_H_
#define HOST_H_
using namespace std;

class host
{
	public:
		int startserver();
		int sendDataServer (int sockfd, string input);
		int receiveDataServer (int sockfd);
		char* getBufServer();
		void clearBufServer();		
};

#endif HOST_H_