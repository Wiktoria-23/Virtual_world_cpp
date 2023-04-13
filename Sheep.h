#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
	Sheep(int xPosition, int yPosition, World* newWorld);
	~Sheep();
};