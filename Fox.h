#pragma once
#include "Animal.h"

class Fox : public Animal {
public:
	Fox(int xPosition, int yPosition, World* newWorld);
	void action() override;
	bool checkIfAnyMovePossible();
	bool checkField(direction moveDirection);
	~Fox();
};