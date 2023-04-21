#pragma once
#include "Plant.h"
#define GRASS_IMAGE 'T'

class Grass : public Plant {
public:
	Grass(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	void collision(Organism* collidingOrganism) const override;
	~Grass();
};