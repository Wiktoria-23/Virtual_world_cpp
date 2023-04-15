#include "SosnowskyHogweed.h"

SosnowskyHogweed::SosnowskyHogweed(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = 10;
	image = 'B';
}
Organism* SosnowskyHogweed::createChild(int xPosition, int yPosition) const {
	Organism* newSosnowskyHogweed = new SosnowskyHogweed(xPosition, yPosition, currentWorld);
	return newSosnowskyHogweed;
}
void SosnowskyHogweed::action() {

}
void SosnowskyHogweed::collision() {

}
SosnowskyHogweed::~SosnowskyHogweed() {

}