#pragma once
#include "Plant.h"
#define DANDELION_IMAGE 'M'

class Dandelion : public Plant {
public:
	Dandelion(int xPosition, int yPosition, World* newWorld);
	virtual Organism* createChild(int xPosition, int yPosition) const override;
	void action() override;
	~Dandelion();
};