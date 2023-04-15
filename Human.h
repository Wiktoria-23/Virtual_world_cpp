#ifndef HUMAN_H
#define HUMAN_H

#pragma once
#include "Animal.h"

class Human : public Animal {
private:
	bool superpowerActive;
	direction moveDirection;
public:
	Human(int xPosition, int yPosition, World* newWorld);
	void setMoveDirection(direction newMoveDirection);
	void action() override;
	void collision() override;
	~Human();
};

#endif // !HUMAN_H