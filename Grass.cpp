#include "Grass.h"

Grass::Grass(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	image = GRASS_IMAGE;
}
Organism* Grass::createChild(int xPosition, int yPosition) const {
	Organism* newGrass = new Grass(xPosition, yPosition, this->currentWorld);
	return newGrass;
}
void Grass::collision(Organism* collidingOrganism) const {

}
Grass::~Grass() {

}