#pragma once
#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope();
	void action() override;
	void collision() override;
	~Antelope();
};