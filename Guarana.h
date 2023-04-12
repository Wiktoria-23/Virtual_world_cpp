#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana();
	void collision() override;
	~Guarana();
};