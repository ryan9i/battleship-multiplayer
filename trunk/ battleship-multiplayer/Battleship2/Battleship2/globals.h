#ifndef GLOBALS_H_
#define GLOBALS_H_

/**********************************************************
Game Global Data
***********************************************************/
#define TRUE    0
#define FALSE   1

#define HORIZONTAL 0
#define VERTICAL 1

#define SUCCESS         0
#define INVALID_INDEX   -1
#define ALREADY_HIT     -2

/**********************************************************
Game Constants and Definitions Content 
***********************************************************/

// The size of the grids
extern int CURRENT_VERSION_NUMBER;
extern int MAX_GRID_X;
extern int MAX_GRID_Y;
extern int NUMBER_OF_ENITIES;

/*
#define MAX_GRID_X 10
#define MAX_GRID_Y 10

// The number of entities in the game
#define NUMBER_OF_ENTITIES 6
*/

/**********************************************************
Server Constants and Definitions Content 
***********************************************************/
#define BACKLOG 10							// how many pending connections queue will hold
#define MAXDATASIZE 100						// max number of bytes we can get at once
#define PORT 60000



#endif GLOBALS_H_