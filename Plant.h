#pragma once
#include "Organism.h"

class Plant : public Organism {
public:
	Plant();
	virtual void action() override;
	virtual void collision() override;
	~Plant();
};