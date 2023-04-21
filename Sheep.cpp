#include "Sheep.h"

Sheep::Sheep(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = SHEEP_STRENGTH;
	initiative = SHEEP_INITIATIVE;
	image = SHEEP_IMAGE;
}
Organism* Sheep::createChild(int xPosition, int yPosition) const {
	Organism* newSheep = new Sheep(xPosition, yPosition, currentWorld);
	return newSheep;
}
Sheep::~Sheep() {

}