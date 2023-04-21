#pragma once
#include "Animal.h"
#define SHEEP_IMAGE 'O'
#define SHEEP_STRENGTH 4
#define SHEEP_INITIATIVE 4

class Sheep : public Animal {
public:
	Sheep(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	~Sheep();
};