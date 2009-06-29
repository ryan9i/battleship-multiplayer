/**********************************************************
Grid.cpp
***********************************************************/

#include "grid.h"
#include "globals.h"
#include <stdio.h>

// The constructor for grid
grid::grid(int sizeX, int sizeY):MAX_X(sizeX), MAX_Y(sizeY)
{
	gridMap = new COORD*[sizeX];
	for (int x = 0; x < MAX_X; ++x)
	{
		gridMap[x] = new COORD[MAX_Y];
	}
}

// Destructor for grid
grid::~grid()
{
	for (int x = 0; x < MAX_X; ++x)
	{
		delete[] gridMap[x];
	}

	delete[] gridMap;
}

// Clears the board of hits and entities
void grid::reset()
{
    // Clear the grid
    for (int x = 0; x < MAX_X; ++x)
    {
        for (int y = 0; y < MAX_Y; ++y)
        {
			gridMap[x][y].entityId = 0;
			gridMap[x][y].hit = FALSE;
        }
    }
}

// Will set the target entities hit status to true
// Returns the entityId of what was hit
int grid::hit(int x, int y)
{
    if ( (MAX_X < x) || (MAX_Y < y) )
    {
        return INVALID_INDEX;
    }
    if ( getHit(x,y) == TRUE )
    {
        return ALREADY_HIT;
    }
    gridMap[x][y].hit = TRUE;
	return gridMap[x][y].entityId;
}

// Will return whether or not the entity has been hit already
int grid::getHit(int x, int y)
{
	if ( (MAX_X < x) || (MAX_Y < y) )
    {
        return INVALID_INDEX;
    }
	return gridMap[x][y].entityId;
}

// Places an entity at a given location
// Returns success
int grid::placeEntity(int x, int y, bool orientation, entity* newEntity)
{
	if ( (MAX_X < x) || (MAX_Y < y) )
    {
        return INVALID_INDEX;
    }
	
	// TODO:
	// These two branches are basically the same code with just two variable differences
	// How do I consolidate them?
	if (orientation == HORIZONTAL)
	{
		if (x + newEntity->size > MAX_X)
		{
			return INVALID_INDEX;
		}

		for (int iter = x; iter < x + newEntity->size; ++iter)
		{
			// TODO:
			// Check that you're not stepping on someones toes
			if (gridMap[iter][y].hit == TRUE)
			{
				// If there is already a hit there
			}
			else if (gridMap[iter][y].entityId != 0)
			{
				// If there is a non zero entitiy
				// assumming that 0 is some constant
				// should that be read from the file?
				// "placeable" terrain?
			}
		}
		for (int iter = x; iter < x + newEntity->size; gridMap[iter++][y].entityId = newEntity->id) {}
	}
	else // (orientation == VERTICAL)
	{
		if (y + newEntity->size > MAX_Y)
		{
			return INVALID_INDEX;
		}

		for (int iter = y; iter < y + newEntity->size; ++iter)
		{
			// TODO:
			// Check that you're not stepping on someones toes
			if (gridMap[x][iter].hit == TRUE)
			{
				// If there is already a hit there
			}
			else if (gridMap[x][iter].entityId != 0)
			{
				// If there is a non zero entitiy
				// assumming that 0 is some constant
				// should that be read from the file?
				// "placeable" terrain?
			}
		}
		for (int iter = y; iter < y + newEntity->size; gridMap[x][iter++].entityId = newEntity->id) {}
	}
	return SUCCESS;
}

// Print out the grid
// Optionally, also print out the entities ontop as well
void grid::printGrid(bool printEntities)
{
    printf("-- Grid --\n\n");
    for (int x = 0; x < MAX_X; ++x)
    {
        // Print out the the row of X's at the top
        if (x == 0)
        {
            printf("   ");
            for (int x1 = 0; x1 < MAX_X; ++x1)
            {
				// TODO: use format
                printf("%d ", x1);
            }
            printf("\n");
        }
        for (int y = 0; y < MAX_Y; ++y)
        {
            // Print out the column name once
            if (y == 0)
            {
				// TODO: use format
                printf("%y ", y);
            }
            
            if (gridMap[x][y].hit == FALSE)
            {
				if (printEntities == TRUE)
				{
					printf("%d ", gridMap[x][y].entityId);
				}
				else
				{
					printf("  ");
				}
            }
            else
            {
                if (printEntities == TRUE)
				{
					printf("%d%s", gridMap[x][y].entityId, HIT);
				}
				else
				{
					printf("%s ", HIT);
				}
            }
        }
        printf("\n");

		if (printEntities == TRUE)
		{
			// TODO
			// Print  entity legend
		}
    }
}