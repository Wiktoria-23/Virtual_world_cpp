#pragma once
#include "Plant.h"
#define SOSNOWSKY_HOGWEED_IMAGE 'B'
#define SOSNOWSKY_HOGWEED_STRENGTH 10

class SosnowskyHogweed : public Plant {
public:
	SosnowskyHogweed(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	void action() override;
	void collision(Organism* collidingOrganism) override;
	~SosnowskyHogweed();
};