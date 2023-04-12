#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion();
	void action() override;
	~Dandelion();
};