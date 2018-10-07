#include <iostream>
#include "World.h"
using namespace std;
int main()
{
    World myWorld; // creates a world object
    myWorld.display(); // creates a board for that world
    char ENTER; 
	while (cin.get(ENTER)) // whenever the "ENTER" button is pressed..
	{
		myWorld.oneForward(); // move the game forward one time space
		myWorld.display(); // re-display the updated board
	}
    return 0;
}
