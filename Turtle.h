#pragma once
#include "Animal.h"

class Turtle : public Animal {
public:
	Turtle(int XPosition, int yPosition, World* newWorld);
	void action() override;
	void collision() override;
	~Turtle();
};