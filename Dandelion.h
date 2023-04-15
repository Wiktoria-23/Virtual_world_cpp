#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(int xPosition, int yPosition, World* newWorld);
	virtual Organism* createChild(int xPosition, int yPosition) const override;
	void action() override;
	~Dandelion();
};