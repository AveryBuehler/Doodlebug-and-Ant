#include <iostream>
#include <cstdlib> 
#include "World.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "windows.h"
using namespace std;


int iterations = 0;

World::World() // creates the world
{ 
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            board[i][j] = NULL;
        }
    }
    spawnOrg(ant, 100); // spawns in 100 ants
    spawnOrg(doodlebug, 5); // spawns in 5 doodlebugs
}
Organism* World::whatIs(int x, int y) const // determines what the organism is at the X and Y location
{
    if ((x >= 0) && (x < 20) && (y >= 0) && (y < 20)) 
	{
        return board[x][y];
    } else 
	{
        return NULL;
    }
}
void World::spawn(int x, int y, Organism* org) // spawns either a doodlebug or an ant at the X and Y location
{
    if ((x >= 0) && (x < 20) && (y >= 0) && (y < 20)) 
	{
        board[x][y] = org;
    }
}
void World::display() const 
{
    int numAnts = 0;
    int numDoodlebugs = 0;
	cout << endl;
    for (int j = 0; j < 20; j++) 
	{
        for (int i = 0; i < 20; i++) 
		{
            if (board[i][j] == NULL) 
			{
				cout << "-"; // places a tile if it's empty
            } else {
                if (board[i][j]->getType() == ant) 
				{
                    numAnts++;
                }
                else if (board[i][j]->getType() == doodlebug) 
				{
                    numDoodlebugs++;
                }
                cout << board[i][j]->boardUpdated(); // outputs the board with ants and doodlebugs
            }
        }
        cout << endl;
    }
	cout << "Iterations: " << iterations;
	iterations++;
}
void World::oneForward() 
{
    origin();
    move(doodlebug);
    move(ant);
    despawn();
    breed();
}
Position World::ranPos() const { // gets a random position
    Position p;
    p.x = rand() % 20;
    p.y = rand() % 20;
    return p;
}
Move World::ranMove() const // moves randomly
{
    return static_cast<Move>(rand() % 4);
}
void World::spawnOrg(OrganismType orgType, int count) 
{
    int orgCount = 0;
    while (orgCount < count) 
	{
        Position p = ranPos();
        if (board[p.x][p.y] == NULL)  // will only spawn if there's nothing else there
		{
            orgCount++;
            if (orgType == ant) 
			{
                new Ant(this, p.x, p.y);   // creates a new ant creature
            }
            else if (orgType == doodlebug) 
			{
                new Doodlebug(this, p.x, p.y);   // creates a new doodlebug creature
            }
        }
    }
}
void World::origin() // places the organisms back into their original state
{
    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if(board[i][j] != NULL)
            {
                board[i][j]->setMoved(false);
            }
        }
    }
}
void World::move(OrganismType org) // moving method
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(board[i][j] != NULL)
            {
                if(board[i][j]->getType() == org && !(board[i][j]->hasMoved()))
                {
                    board[i][j]->move();
                }
            }
        }
    }
}
void World::despawn() // despawning method
{
    for (int i = 0; i < 20; i++) 
	{
        for (int j = 0; j < 20; j++) 
		{
            if ((board[i][j] != NULL) && board[i][j]->isDead()) // finds which Doodlebugs haven't eaten and kills them
			{
                delete board[i][j];
                board[i][j] = NULL;
            }
        }
    }
}
void World::breed() // breeding method
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(board[i][j] != NULL)
            {
                board[i][j]->breed();
            }
        }
    }
}
