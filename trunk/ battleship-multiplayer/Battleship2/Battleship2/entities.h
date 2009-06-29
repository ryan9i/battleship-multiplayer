/**********************************************************
Entities.h
***********************************************************/
#ifndef ENTITIES_H_
#define ENTITIES_H_

typedef struct 
{
	int id;
    char *name;
    int size;
} entity;

typedef struct 
{
	entity *theEntity;
	int x;
	int y;
	bool orientation;
} entityMap;

class entitiesList
{
	public:
		entitiesList();

		// List of entities
		entity* entityList;
		void addEntity(entity *newEntity);
		int removeEntity(char *name);

		int read(void);
		int write(void);
};

#endif ENTITIES_H_