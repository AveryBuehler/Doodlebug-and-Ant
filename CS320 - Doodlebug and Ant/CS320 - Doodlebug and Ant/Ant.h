#include <iostream>
#include "Organism.h"
#include "World.h"

class Ant : public Organism
{
public:
    Ant(World* antWorld, int xP, int yP);
    void move();
    void breed();
    OrganismType getType() const;
    char boardUpdated() const;
    int size() const;
    bool detPlace(int xx, int yy);
private:
    void breedOrg(int whereX, int whereY);
};
