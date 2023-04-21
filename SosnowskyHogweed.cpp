#include "SosnowskyHogweed.h"
#include "Animal.h"

SosnowskyHogweed::SosnowskyHogweed(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = SOSNOWSKY_HOGWEED_STRENGTH;
	image = SOSNOWSKY_HOGWEED_IMAGE;
}
Organism* SosnowskyHogweed::createChild(int xPosition, int yPosition) const {
	Organism* newSosnowskyHogweed = new SosnowskyHogweed(xPosition, yPosition, currentWorld);
	return newSosnowskyHogweed;
}
void SosnowskyHogweed::action() {
	if (currentWorld->checkFieldXY(x - 1, y) && currentWorld->checkIfAnimal(x - 1, y)) {
		currentWorld->killOrganismFromXY(x - 1, y);
	}
	if (currentWorld->checkFieldXY(x + 1, y) && currentWorld->checkIfAnimal(x + 1, y)) {
		currentWorld->killOrganismFromXY(x + 1, y);
	}
	if (currentWorld->checkFieldXY(x, y - 1) && currentWorld->checkIfAnimal(x, y - 1)) {
		currentWorld->killOrganismFromXY(x, y - 1);
	}
	if (currentWorld->checkFieldXY(x, y + 1) && currentWorld->checkIfAnimal(x, y + 1)) {
		currentWorld->killOrganismFromXY(x, y + 1);
	}
	grow();
}
void SosnowskyHogweed::collision(Organism* collidingOrganism) const {

}
SosnowskyHogweed::~SosnowskyHogweed() {

}