#pragma once
#include "Animal.h"

class Turtle : public Animal {
public:
	Turtle();
	void action() override;
	void collision() override;
	~Turtle();
};