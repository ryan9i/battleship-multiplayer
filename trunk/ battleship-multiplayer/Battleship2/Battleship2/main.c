// #include <stdio.h>
// #include "globals.h"
// #include "direct.h"
// #include "grid.h"
// #include "entities.h"

/**********************************************************
Entities.h
***********************************************************/
// #ifndef ENTITIES_H_
// #define ENTITIES_H_

typedef struct 
{
    char *name;
    int size;
} entity;

class entitiesList
{
    // List of entities
    entity* entityList;

    entitiesList();
    void addEntity(entity *newEntity);
    removeEntity(char *name);
};

// #endif ENTITIES_H_

/**********************************************************
Entities.cpp
***********************************************************/
// #include "entities.h"

entitiesList::entitiesList()
{
    // Read from a file the number of entities
    // go through each entity and read in the name and size
}

void entitiesList::addEntity();
{
    // Add an entity based on an entity pointer
}

/**********************************************************
Grid.h
***********************************************************/
/*
#ifndef GRID_H_
#define GRID_H_

// Each "square" of the grid
struct coord 
{ 
    enum entity value;  // What entity is in the square
    char hit;           // Whether or not this square has been hit
} typedef COORD;

class Grid
{
    public:
        Grid();
        short hit(int x, int y);
        char getHit(int x, int y);
        void reset();
        void printHitsGrid();
        void printEntireGrid();
    private:
        COORD grid[MAX_GRID_X][MAX_GRID_Y];
        void setValue(int x, int y, int newValue, char newHit);
};

#endif GRID_H_

/**********************************************************
Grid.cpp
***********************************************************/
/*
// #include "grid.h"

// The constructor for grid
// Setups up the board with default values using reset
Grid::Grid() 
{
    reset();
}

// Will hit a target
// If a target has no health left (all of it has been sunk)
// then it returns the value of what was sunk
short Grid::hit(int x, int y)
{
    if ( (MAX_GRID_X < x) || (MAX_GRID_Y < y) )
    {
        return INVALID_INDEX;
    }
    if (getHit(x,y) == TRUE)
    {
        return ALREADY_HIT;
    }

    grid[x,y]->hit = TRUE;
    --(gridEntities[grid[x,y]->value].health);

    // See if said entity has no health left
    // i.e. all its squares have been hit
    if (gridEntities[grid[x,y]->value].health == 0)
    {
        return (grid[x,y]->value);
    }
    return SUCCESS;
}

// Just returns whether or not something was hit
char Grid::getHit(int x, int y)
{
    if ( (MAX_GRID_X < x) || (MAX_GRID_Y < y) )
    {
        return INVALID_INDEX;
    }
    return (grid[x,y]->hit);
}

// Clears the board and sets the healths back to full
void Grid::reset()
{
    // Clear the grid
    for (int x = 0; x < MAX_GRID_X; ++x)
    {
        for (int y = 0; y < MAX_GRID_Y; ++y)
        {
            grid[x,y]->hit = FALSE;
            grid[x,y]->value = water;
        }
    }

    // Clear the grid entities
    for (int x = 0; x < NUMBER_OF_ENTITIES; ++x)
    {
        gridEntities[x].value = (entity)x;
        gridEntities[x].health = entity_size[x];
    }
}

// General accessor function
void Grid::setValue(int x, int y, int newValue, char newHit)
{
    grid[x,y]->value = (entity)newValue;
    grid[x,y]->hit = newHit;
}

void Grid::printHitsGrid()
{
    printf("Hits map\n\n");
    for (int x = 0; x < MAX_GRID_X; ++x)
    {
        // Print out the the row of X's at the top
        if (x == 0)
        {
            printf("   ");
            for (int x1 = 0; x1 < MAX_GRID_X; ++x1)
            {
                printf("[%d], ", x1);
            }
            printf("\n");
        }
        for (int y = 0; y < MAX_GRID_Y; ++y)
        {
            // Print out the column name once
            if (y == 0)
            {
                printf("[%y], ", y);
            }
            
            if (grid[x,y]->hit == FALSE)
            {
                printf("X, ");
            }
            else
            {
                printf("O, ");
            }
        }
        printf("\n");
    }
}

void Grid::printEntireGrid()
{
    printf("Entire map\n\n");
    for (int x = 0; x < MAX_GRID_X; ++x)
    {
        // Print out the the row of X's at the top
        if (x == 0)
        {
            printf("   ");
            for (int x1 = 0; x1 < MAX_GRID_X; ++x1)
            {
                printf("[%d], ", x1);
            }
            printf("\n");
        }
        for (int y = 0; y < MAX_GRID_Y; ++y)
        {
            // Print out the column name once
            if (y == 0)
            {
                printf("[%y], ", y);
            }
            
            if (grid[x,y]->hit == FALSE)
            {
                printf("%dX, ", grid[x,y]->value);
            }
            else
            {
                printf("%dO, ", grid[x,y]->value);
            }
        }
        printf("\n");
    }
}

/**********************************************************
Main
***********************************************************/
int main()
{
    return 0;
}