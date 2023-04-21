#pragma once
#include "Animal.h"
#define TURTLE_IMAGE 'Z'
#define TURTLE_STRENGTH 2
#define TURTLE_INITIATIVE 1

class Turtle : public Animal {
public:
	Turtle(int XPosition, int yPosition, World* newWorld);
	void action() override;
	void collision(Organism* collidingOrganism) const override;
	Organism* createChild(int xPosition, int yPosition) const override;
	~Turtle();
};