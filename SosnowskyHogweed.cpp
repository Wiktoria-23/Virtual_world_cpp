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
bool SosnowskyHogweed::checkIfAnimal(int xPosition, int yPosition) {
	Organism* neighbourOrganism;
	if (currentWorld->checkFieldXY(xPosition, yPosition)) {
		neighbourOrganism = &currentWorld->getOrganismFromXY(xPosition, yPosition);
	}
	else {
		neighbourOrganism = nullptr;
	}
	if (neighbourOrganism != nullptr) {
		Animal* animalPointer = dynamic_cast<Animal*>(neighbourOrganism);
		if (animalPointer != nullptr) {
			return true;
		}
	}
	return false;
}
void SosnowskyHogweed::action() {
	if (checkIfAnimal(x - 1, y)) {
		currentWorld->killOrganismFromXY(x - 1, y);
	}
	if (checkIfAnimal(x + 1, y)) {
		currentWorld->killOrganismFromXY(x + 1, y);
	}
	if (checkIfAnimal(x, y - 1)) {
		currentWorld->killOrganismFromXY(x, y - 1);
	}
	if (checkIfAnimal(x, y + 1)) {
		currentWorld->killOrganismFromXY(x, y + 1);
	}
	grow();
}
void SosnowskyHogweed::collision(Organism* collidingOrganism) const {

}
SosnowskyHogweed::~SosnowskyHogweed() {

}