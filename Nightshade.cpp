#include "Nightshade.h"

Nightshade::Nightshade(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = NIGHTSHADE_STRENGTH;
	image = NIGHTSHADE_IMAGE;
}
Organism* Nightshade::createChild(int xPosition, int yPosition) const {
	Organism* newNightshade = new Nightshade(xPosition, yPosition, currentWorld);
	return newNightshade;
}
void Nightshade::collision(Organism* collidingOrganism) {
	//kills an animal
}
Nightshade::~Nightshade() {

}