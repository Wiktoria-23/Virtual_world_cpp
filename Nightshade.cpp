#include "Nightshade.h"

Nightshade::Nightshade(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = 99;
	image = 'J';
}
Organism* Nightshade::createChild(int xPosition, int yPosition) const {
	Organism* newNightshade = new Nightshade(xPosition, yPosition, currentWorld);
	return newNightshade;
}
void Nightshade::collision() {
	//kills an animal
}
Nightshade::~Nightshade() {

}