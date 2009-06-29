#include <string>
#include "aircraft_carrier.h"
using namespace std;


void aircraft_carrier::location (int x_input, int y_input, bool horizontal_input)
{
	x=x_input;
	y=y_input;
	horizontal_input=horizontal;
	for (int i=0;i<5;i++)
	{
		damage[i]=false;
	}
	sunk=false;
}

bool aircraft_carrier::hit(int targetx, int targety)
{
	if (horizontal)
	{
		for (int i=0; i<5;i++)
		{
			if (x==targetx && y+i==targety)
			{
				damage[i]=true;
				checkDamage();
				return true;
			}
		}
	}
	else
	{
		for (int i=0; i<5;i++)
		{
			if (x+i==targetx && y==targety)
			{
				damage[i]=true;
				checkDamage();
				return true;
			}
		}
	}
	return false;
}
void aircraft_carrier::checkDamage()
{
	if(damage[0]&&damage[1]&&damage[2]&&damage[3]&&damage[4])
	{
		sunk=true;
	}
}
bool aircraft_carrier::getSunk()
{
	return  sunk;
}