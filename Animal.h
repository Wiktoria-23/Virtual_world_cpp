#ifndef ANIMAL_H
#define ANIMAL_H

#pragma once
#include "Organism.h"
#include <stdlib.h>

class Animal : public Organism {
protected:
	int speed = 1;
public:
	Animal(int xPosition, int yPosition, World* newWorld);
	virtual void action() override;
	virtual void collision() override;
	void baseMovement(direction moveDirection);
	bool checkMove(direction moveDirection);
};

#endif // !ANIMAL_H