#include "Dandelion.h"

Dandelion::Dandelion(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	image = DANDELION_IMAGE;
}
Organism* Dandelion::createChild(int xPosition, int yPosition) const {
	Organism* newDandelion = new Dandelion(xPosition, yPosition, currentWorld);
	return newDandelion;
}
void Dandelion::action() {
	for (int i = 0; i < 3; i++) {
		grow();
	}
}
Dandelion::~Dandelion() {

}