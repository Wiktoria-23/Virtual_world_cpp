#include "Wolf.h"

Wolf::Wolf(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = WOLF_STRENGTH;
	initiative = WOLF_INITIATIVE;
	image = WOLF_IMAGE;
}
Organism* Wolf::createChild(int xPosition, int yPosition) const {
	Organism* newWolf = new Wolf(xPosition, yPosition, currentWorld);
	return newWolf;
}
Wolf::~Wolf() {

}