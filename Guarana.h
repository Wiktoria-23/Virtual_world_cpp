#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	void collision() override;
	~Guarana();
};