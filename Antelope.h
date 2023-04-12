#pragma once
#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope(int xPosition, int yPosition);
	void action() override;
	void collision() override;
	~Antelope();
};