#pragma once
#include "Plant.h"

class SosnowskyHogweed : public Plant {
public:
	SosnowskyHogweed(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	bool checkIfAnimal(int xPosition, int yPosition);
	void action() override;
	void collision() override;
	~SosnowskyHogweed();
};