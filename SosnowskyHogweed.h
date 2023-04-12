#pragma once
#include "Plant.h"

class SosnowskyHogweed : public Plant {
public:
	SosnowskyHogweed(int xPosition, int yPosition);
	void action() override;
	void collision() override;
	~SosnowskyHogweed();
};