#pragma once
#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope(int xPosition, int yPosition, World* newWorld);
	void action() override;
	void collision() override;
	~Antelope();
};