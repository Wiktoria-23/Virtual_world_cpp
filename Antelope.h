#pragma once
#include "Animal.h"
#define ANTELOPE_IMAGE 'A'
#define ANTELOPE_INITIATIVE 4
#define ANTELOPE_STRENGTH 4
#define ANTELOPE_SPEED 2

class Antelope : public Animal {
public:
	Antelope(int xPosition, int yPosition, World* newWorld);
	void collision(Organism* collidingOrganism) override;
	void setSpeed(int newSpeed);
	Organism* createChild(int xPosition, int yPosition) const override;
	~Antelope();
};