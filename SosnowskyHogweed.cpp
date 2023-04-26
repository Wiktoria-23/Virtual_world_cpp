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
		currentWorld->getOrganismFromXY(x - 1, y).setDeadState();
		currentWorld->addDeathInfo(currentWorld->getOrganismFromXY(x - 1, y), *this);
	}
	if (currentWorld->checkFieldXY(x + 1, y) && currentWorld->checkIfAnimal(x + 1, y)) {
		currentWorld->getOrganismFromXY(x + 1, y).setDeadState();
		currentWorld->addDeathInfo(currentWorld->getOrganismFromXY(x + 1, y), *this);
	}
	if (currentWorld->checkFieldXY(x, y - 1) && currentWorld->checkIfAnimal(x, y - 1)) {
		currentWorld->getOrganismFromXY(x, y - 1).setDeadState();
		currentWorld->addDeathInfo(currentWorld->getOrganismFromXY(x, y - 1), *this);
	}
	if (currentWorld->checkFieldXY(x, y + 1) && currentWorld->checkIfAnimal(x, y + 1)) {
		currentWorld->getOrganismFromXY(x, y + 1).setDeadState();
		currentWorld->addDeathInfo(currentWorld->getOrganismFromXY(x, y + 1), *this);
	}
	grow();
}
void SosnowskyHogweed::collision(Organism* collidingOrganism) {
	setDeadState();
	collidingOrganism->setDeadState();
	currentWorld->addDeathInfo(*collidingOrganism, *this);
	currentWorld->addDeathInfo(*this, *collidingOrganism);
}
SosnowskyHogweed::~SosnowskyHogweed() {

}