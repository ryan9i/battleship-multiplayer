#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>

#include "main.h"
#include "globals.h"
#include "entities.h"
#include "grid.h"
//#include "direct.h" what is this? did you not commit it?
#include "host.h"
#include "client.h"
#include "encoding.h"
#include "navy.h"

#include <iostream>
#include <fstream>

using namespace std;

/**********************************************************
Main
***********************************************************/
int main()
{
	// Read the file version number
	// Read the max grid #'s
	// Read the grid hit co-ordinates (if any)
	// Read the # of entities
	// Read the entities
	// Read turn (if any)
	navy n;
	n.aircraftCarrier.location(1,1,false);
	//aircraft_carrier a;
	//a.location(2,2,true);
	//bool temp = a.hit(2,2);
	//temp = a.hit(2,3);
	//temp = a.hit(2,4);
	//temp = a.hit(2,5);
	//temp = a.getSunk();
	//temp = a.hit(2,6);
	//temp = a.getSunk();



    return 0;
}







//TEST CODE FOR NETWORK STUFF ******************************
	//string input, ip;
	//int choice, sequence=0;
	//printf("Hello, please choose from the following choices\n 1 to host\n 2 to connect\n JUST ENTER THE NUMBER\n");
	//cin >> choice;

	//if (choice ==1)
	//{
	//	host b;
	//	int new_fd = b.startserver();
	//	
	//	b.sendDataServer(new_fd,"Hello new connection welcome to my server!\n");
	//	while(1) {
	//		b.receiveDataServer(new_fd);
	//		printf(b.getBufServer());
	//		b.clearBufServer();
	//		printf("\n");
	//		sequence++;
	//		if (sequence ==1) //for server
	//		{
	//			std::getline(std::cin, input); //for some reason on the first run of this loop for the server this line is run, but skipped or something, i can't for the life of me right now figure it out so i had to do this.
	//		}
	//		std::getline(std::cin, input);
	//		b.sendDataServer(new_fd,input);
	//	}
	//}

	//if (choice ==2)
	//{
	//	printf("IP? \n");
	//	cin >> ip;
	//	client a;
	//	int temp = a.clientConnect(ip);
	//	int bytes_recv;
	//	while(1) {
	//		std::getline(std::cin, input);
	//		a.sendData(temp,input);
	//		sequence++;
	//		bytes_recv = a.receiveData(temp);
	//		printf(a.getBuf());
	//		a.clearBuf();
	//		printf("\n");
	//	}
 //   }
	//END OF TEST CODE FOR NETWORKSTUFF