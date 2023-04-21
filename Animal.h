#ifndef ANIMAL_H
#define ANIMAL_H

#pragma once
#include "Organism.h"
#include <stdlib.h>

class Animal : public Organism {
protected:
	int speed = 1;
	direction moveDirection;
public:
	Animal(int xPosition, int yPosition, World* newWorld);
	virtual void action() override;
	virtual void collision(Organism* collidingOrganism) const override;
	void setMoveDirection(direction newMoveDirection);
	void baseMovement();
	bool checkMove(direction moveDirection);
	bool checkSameType(Organism* collidingOrganism);
	/*virtual void breed();*/ //napisac rozmnazanie
	virtual Organism* createChild(int xPosition, int yPosition) const override = 0;
};

#endif // !ANIMAL_H