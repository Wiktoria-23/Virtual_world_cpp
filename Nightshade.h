#pragma once
#include "Plant.h"

class Nightshade : public Plant {
public:
	Nightshade(int xPosition, int yPosition);
	void collision() override;
	~Nightshade();
};