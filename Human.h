#pragma once
#include "Animal.h"

class Human : public Animal {
private:
	bool superpowerActive;
public:
	Human(int xPosition, int yPosition, World* newWorld);
	void action() override;
	void collision() override;
	~Human();
};