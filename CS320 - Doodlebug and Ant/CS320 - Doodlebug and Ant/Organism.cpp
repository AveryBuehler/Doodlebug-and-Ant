#include <iostream>
#include "Organism.h"
#include "World.h"
Organism::Organism(World* antWorld, int xP, int yP) 
{
    world = antWorld;
    x = xP;
    y = yP;
    tempCount = 0;
    moved = false;
    world->spawn(x, y, this);
}
void Organism::setMoved(bool hasMoved) 
{
    moved = hasMoved;
}
bool Organism::hasMoved() const 
{
    return moved;
}
void Organism::movesTo(int xNew, int yNew) 
{
        world->spawn(xNew, yNew, world->whatIs(x, y));
        world->spawn(x, y, NULL);
        x = xNew;
        y = yNew;
    world->whatIs(x, y)->setMoved(true);
}
void Organism::breedNear()  
{
    
    if((world->whatIs(x, y + 1) == NULL) && detPlace(x, y + 1))
    {
        breedOrg(x, y + 1);
    }
    else if((world->whatIs(x, y - 1) == NULL) && detPlace(x, y - 1))
    {
        breedOrg(x, y - 1);
    }
    else if((world->whatIs(x - 1, y) == NULL)  && detPlace(x - 1, y))
    {
        breedOrg(x - 1, y);
    }
    else if((world->whatIs(x + 1, y) == NULL)  && detPlace(x + 1, y))
    {
        breedOrg(x + 1, y);
    }
}


bool Organism::detPlace(int xx, int yy)
{
    return (xx >= 0) && (xx < 20) && (yy >= 0) && (yy < 20);
}
bool Organism::isDead() const 
{
    return false;
}
