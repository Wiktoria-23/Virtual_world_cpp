#pragma once
#include "Animal.h"

class Fox : public Animal {
public:
	Fox();
	void action() override;
	~Fox();
};