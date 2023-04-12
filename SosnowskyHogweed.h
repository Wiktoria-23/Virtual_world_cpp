#pragma once
#include "Plant.h"

class SosnowskyHogweed : public Plant {
public:
	SosnowskyHogweed();
	void action() override;
	void collision() override;
	~SosnowskyHogweed();
};