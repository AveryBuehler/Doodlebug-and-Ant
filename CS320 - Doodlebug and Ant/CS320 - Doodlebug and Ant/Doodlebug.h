#include <iostream>
#include "World.h"
#include "Organism.h"

class Doodlebug:public Organism
{
public:
    Doodlebug(World* antWorld, int xP, int yP);
    void move();
    void breed();
    OrganismType getType() const;
    char boardUpdated() const;
    int size() const;
    bool isDead() const;
    bool detPlace(int xx, int yy);
private:
    void breedOrg(int whereX, int whereY);
    int deadNum;
};
