#ifndef WORLD_H
#define WORLD_H
#include "Organism.h"
enum Move // possible movements for the ant & doodlebug
{ 
	UP = 0, 
	DOWN, 
	LEFT, 
	RIGHT
};
struct Position // creating a Position struct with the X and Y values of the ant or doodlebug
{
    int x;
    int y;
};
class World
{
    public:
		World();
        Organism* whatIs(int x, int y) const; // recieves the position of the ant or doodlebug
        void spawn(int x, int y, Organism* org); // spawns an ant or doodlebug at the location
        void display() const; // displays the world
        void oneForward(); // acts as one time frame in the program
        Position ranPos() const; // gets a random position on the board for movement purposes
        Move ranMove() const; // uses the ENUM type above to move randomly
    private:
        Organism* board[20][20]; // creates a 20x20 board
        void spawnOrg(OrganismType orgType, int count); // spawns in ants or doodlebugs
        void origin(); // resets the timers and makes it so no further moves are made
        void move(OrganismType org); // moves the ant or doodlebug to its next position
        void despawn(); // despawns all dead ants or doodlebugs after the iteration is finished
        void breed(); // breeds an ant or doodlebug if the conditions are met
};
#endif
