#pragma once

#include "Organism.h"
#include <stdlib.h>

enum direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

class Animal : public Organism {
public:
	virtual void action() override;
	virtual void collision() override;
};