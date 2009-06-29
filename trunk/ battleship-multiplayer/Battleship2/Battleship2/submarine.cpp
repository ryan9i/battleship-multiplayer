#include <string>
#include "submarine.h"
using namespace std;


void submarine::location (int x_input, int y_input, bool horizontal_input)
{
	x=x_input;
	y=y_input;
	horizontal_input=horizontal;
	for (int i=0;i<3;i++)
	{
		damage[i]=false;
	}
	sunk=false;
}

bool submarine::hit(int targetx, int targety)
{
	if (horizontal)
	{
		for (int i=0; i<3;i++)
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
		for (int i=0; i<3;i++)
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
void submarine::checkDamage()
{
	if(damage[0]&&damage[1]&&damage[2])
	{
		sunk=true;
	}
}
bool submarine::getSunk()
{
	return  sunk;
}