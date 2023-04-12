#pragma once
#include "Animal.h"

class Human : public Animal {
private:
	bool superpowerActive;
public:
	Human(int xPosition, int yPosition);
	void action() override;
	void collision() override;
	~Human();
};