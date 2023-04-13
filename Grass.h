#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
	Grass(int xPosition, int yPosition, World* newWorld);
	~Grass();
};