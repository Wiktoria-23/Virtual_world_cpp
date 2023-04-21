#include "Antelope.h"

Antelope::Antelope(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	image = ANTELOPE_IMAGE;
	speed = ANTELOPE_SPEED;
	strength = ANTELOPE_STRENGTH;
}
Organism* Antelope::createChild(int xPosition, int yPosition) const {
	Organism* newAntelope = new Antelope(xPosition, yPosition, currentWorld);
	return newAntelope;
}
void Antelope::collision(Organism* collidingOrganism) const {

}
Antelope::~Antelope() {

}