#include "Grass.h"

Grass::Grass(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = 0;
	image = 'T';
}
Organism* Grass::createChild(int xPosition, int yPosition) const {
	Organism* newGrass = new Grass(xPosition, yPosition, this->currentWorld);
	return newGrass;
}
Grass::~Grass() {

}