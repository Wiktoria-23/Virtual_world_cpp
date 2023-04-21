#pragma once
#include "Animal.h"
#define WOLF_IMAGE 'W'
#define WOLF_STRENGTH 9
#define WOLF_INITIATIVE 5

class Wolf : public Animal {
public:
	Wolf(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	~Wolf();
};