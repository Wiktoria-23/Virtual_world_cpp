#pragma once
#include "Plant.h"

class Nightshade : public Plant {
public:
	Nightshade();
	void collision() override;
	~Nightshade();
};