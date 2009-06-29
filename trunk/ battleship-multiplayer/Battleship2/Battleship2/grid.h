/**********************************************************
Grid.h
***********************************************************/
#ifndef GRID_H_
#define GRID_H_

#include "globals.h"
#include "entities.h"

#define HIT "X"

// Each "square" of the grid
struct coord 
{ 
    int entityId;	// What entity is in the square
    bool hit;       // Whether or not this square has been hit
} typedef COORD;

class grid
{
	public:
		// TODO
		// Why or why not shouldn't this be static?
		const int MAX_X;
		const int MAX_Y;
		grid(int sizeX, int sizeY);
		~grid();
		void reset();
		int hit(int x, int y);
		int getHit(int x, int y);
		int placeEntity(int x, int y, bool orientation, entity* newEntity);
		void printGrid(bool printEntities);
		
		int read(void);
		int write(void);

	private:
		COORD **gridMap;
};

#endif GRID_H_