#include <string>
#include "pt_boat.h"
using namespace std;


void ptBoat::location (int x_input, int y_input, bool horizontal_input)
{
	x=x_input;
	y=y_input;
	horizontal_input=horizontal;
	for (int i=0;i<2;i++)
	{
		damage[i]=false;
	}
	sunk=false;
}

bool ptBoat::hit(int targetx, int targety)
{
	if (horizontal)
	{
		for (int i=0; i<2;i++)
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
		for (int i=0; i<2;i++)
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
void ptBoat::checkDamage()
{
	if(damage[0]&&damage[1])
	{
		sunk=true;
	}
}
bool ptBoat::getSunk()
{
	return  sunk;
}