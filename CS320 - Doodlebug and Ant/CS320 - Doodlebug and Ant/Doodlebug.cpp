#include "Doodlebug.h"
#include "Organism.h"
using namespace std;
Doodlebug::Doodlebug(World* antWorld, int xP, int yP) : Organism(antWorld, xP, yP){deadNum = 0;}
void Doodlebug::move()
{
    tempCount++;
    deadNum++;
    if(world->whatIs(x, y + 1) != NULL)
    {
        if(world->whatIs(x, y + 1)->getType() == ant)
        {
            deadNum = 0;
            delete world->whatIs(x, y + 1);
            movesTo(x, y + 1);
            return;
        }
    }
    if(world->whatIs(x, y - 1) != NULL)
    {
        if(world->whatIs(x, y - 1)->getType() == ant)
        {
            deadNum = 0;
            delete world->whatIs(x, y - 1);
            movesTo(x, y - 1);
            return;
        }
    }
    if(world->whatIs(x - 1, y) != NULL)
    {
        if(world->whatIs(x - 1, y)->getType() == ant)
        {
            deadNum = 0;
            delete world->whatIs(x - 1, y);
            movesTo(x - 1, y);
            return;
        }
    }
    if(world->whatIs(x + 1, y) != NULL)
    {
        if(world->whatIs(x + 1, y)->getType() == ant)
        {
            deadNum = 0;
            delete world->whatIs(x + 1, y);
            movesTo(x + 1, y);
            return;
        }
    }
    Move antMovement = world->ranMove();
    switch (antMovement){
        case UP:
            if(world->whatIs(x, y + 1) == NULL && detPlace(x, y + 1))
            {
                movesTo(x, y + 1);
            }
            break;
        case DOWN:
            if(world->whatIs(x, y - 1) == NULL && detPlace(x, y - 1))
            {
                movesTo(x, y - 1);
            }
            break;
        case LEFT:
            if(world->whatIs(x - 1, y) == NULL && detPlace(x - 1, y))
            {
                movesTo(x - 1, y);
            }
            break;
        case RIGHT:
            if(world->whatIs(x + 1, y) == NULL && detPlace(x + 1, y))
            {
                movesTo(x + 1, y);
            }
            break;
        default:
            break;
    }
}
void Doodlebug::breedOrg(int whereX, int whereY)
{
    new Doodlebug(this->world, whereX, whereY);
    tempCount = 0;
}
void Doodlebug::breed()
{
    if(tempCount >= 8)
    {
        breedNear();
    }
    
}
bool Doodlebug::isDead() const
{
    if(deadNum >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
OrganismType Doodlebug::getType() const
{
    return doodlebug;
}
char Doodlebug::boardUpdated()const
{
    return 'X';
}
int Doodlebug::size() const
{
    return 30;
}
bool Doodlebug::detPlace(int xx, int yy)
{
    return (xx >= 0) && (xx < 20) && (yy >= 0) && (yy < 20);
}
