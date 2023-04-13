#pragma once
#include "Organism.h"

class Plant : public Organism {
public:
	Plant(int xPosition, int yPosition, World* newWorld);
	virtual void action() override;
	virtual void collision() override;
	~Plant();
};