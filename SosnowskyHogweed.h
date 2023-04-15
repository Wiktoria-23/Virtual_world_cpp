#pragma once
#include "Plant.h"

class SosnowskyHogweed : public Plant {
public:
	SosnowskyHogweed(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	void action() override;
	void collision() override;
	~SosnowskyHogweed();
};