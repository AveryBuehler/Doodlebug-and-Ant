#ifndef ORGANISM_H
#define ORGANISM_H

enum OrganismType // possible organisms
{
	ant, 
	doodlebug
};
class World;
class Organism {
    public:
        Organism(World* antWorld, int xP, int yP);
        virtual ~Organism() { }
        virtual void move() = 0;
        virtual void breed() = 0;
        virtual OrganismType getType() const = 0;
        void setMoved(bool hasMoved);
        virtual char boardUpdated() const = 0;
        virtual int size() const = 0;
        bool hasMoved() const;
        virtual bool isDead() const;
        bool detPlace(int xx, int yy);
    protected:
        virtual void breedOrg(int whereX, int whereY) = 0;
        void movesTo(int xNew, int yNew);
        void breedNear();
		int x, y, tempCount;
        bool moved;
        World* world;
};
#endif 
