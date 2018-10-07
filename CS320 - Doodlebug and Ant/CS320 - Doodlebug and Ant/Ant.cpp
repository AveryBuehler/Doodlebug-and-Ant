#include <cstdlib>
#include <iostream>
#include "Ant.h"
#include "Organism.h"
#include "World.h"
using namespace std;

Ant::Ant(World* antWorld, int xP, int yP) : Organism(antWorld, xP, yP) {}
void Ant::move()
{
	tempCount++;
	Move antMovement = world->ranMove();
	switch (antMovement) {
	case UP:
		if (world->whatIs(x, y + 1) == NULL && detPlace(x, y + 1))
		{
			movesTo(x, y + 1);
		}
		break;
	case DOWN:
		if (world->whatIs(x, y - 1) == NULL && detPlace(x, y - 1))
		{
			movesTo(x, y - 1);
		}
		break;
	case LEFT:
		if (world->whatIs(x - 1, y) == NULL && detPlace(x - 1, y))
		{
			movesTo(x - 1, y);
		}
		break;
	case RIGHT:
		if (world->whatIs(x + 1, y) == NULL && detPlace(x + 1, y))
		{
			movesTo(x + 1, y);
		}
		break;
	default:
		break;
	}
}
void Ant::breed()
{
    if(tempCount >= 3)
    {
        breedNear();
    }
}
void Ant::breedOrg(int whereX, int whereY)
{
    new Ant(this->world, whereX, whereY);
    tempCount = 0;
}
OrganismType Ant::getType() const
{
    return ant;
}
char Ant::boardUpdated() const
{
    return 'o';
}
int Ant::size() const
{
    return 10;
}
bool Ant::detPlace(int xx, int yy)
{
    return (xx >= 0) && (xx < 20) && (yy >= 0) && (yy < 20);
}
