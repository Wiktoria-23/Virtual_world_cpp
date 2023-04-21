#pragma once
#include "Plant.h"
#define NIGHTSHADE_IMAGE 'J'
#define NIGHTSHADE_STRENGTH 99

class Nightshade : public Plant {
public:
	Nightshade(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	void collision(Organism* collidingOrganism) const override;
	~Nightshade();
};