#pragma once
#include "Plant.h"

class Nightshade : public Plant {
public:
	Nightshade(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	void collision() override;
	~Nightshade();
};