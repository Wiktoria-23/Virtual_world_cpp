#pragma once
#include "Animal.h"

class Fox : public Animal {
public:
	Fox(int xPosition, int yPosition);
	void action() override;
	~Fox();
};