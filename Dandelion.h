#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(int xPosition, int yPosition);
	void action() override;
	~Dandelion();
};