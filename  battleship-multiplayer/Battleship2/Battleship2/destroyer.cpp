#include <string>
#include "destroyer.h"
using namespace std;


void destroyer::location (int x_input, int y_input, bool horizontal_input)
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

bool destroyer::hit(int targetx, int targety)
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
void destroyer::checkDamage()
{
	if(damage[0]&&damage[1]&&damage[2])
	{
		sunk=true;
	}
}
bool destroyer::getSunk()
{
	return  sunk;
}