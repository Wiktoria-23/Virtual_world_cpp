#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(int xPosition, int yPosition, World* newWorld);
	void collision() override;
	~Guarana();
};