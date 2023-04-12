#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(int xPosition, int yPosition);
	void collision() override;
	~Guarana();
};