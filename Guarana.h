#pragma once
#include "Plant.h"
#define GUARANA_IMAGE 'G'

class Guarana : public Plant {
public:
	Guarana(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	void collision(Organism* collidingOganism) const override;
	~Guarana();
};