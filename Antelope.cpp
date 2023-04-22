#include "Antelope.h"

Antelope::Antelope(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	image = ANTELOPE_IMAGE;
	speed = ANTELOPE_SPEED;
	strength = ANTELOPE_STRENGTH;
	initiative = ANTELOPE_INITIATIVE;
}
Organism* Antelope::createChild(int xPosition, int yPosition) const {
	Organism* newAntelope = new Antelope(xPosition, yPosition, currentWorld);
	return newAntelope;
}
void Antelope::setSpeed(int newSpeed) {
	speed = newSpeed;
}
void Antelope::collision(Organism* collidingOrganism) {
	if (collidingOrganism->checkIfAlive() && image != collidingOrganism->getImage()) {
		int survive = rand() % 2;
		if (survive == 0) {
			if (currentWorld->checkFieldXY(x, y - 1) || currentWorld->checkFieldXY(x, y + 1) || currentWorld->checkFieldXY(x - 1, y) || currentWorld->checkFieldXY(x + 1, y)) {
				setSpeed(BASE_ANIMAL_SPEED);
				while (true) {
					direction moveDirection = (direction)(rand() % 4);
					if (checkMove(moveDirection)) {
						setMoveDirection(moveDirection);
						baseMovement();
						setSpeed(ANTELOPE_SPEED);
						break;
					}
				}
			}
		}
		baseFight(collidingOrganism);
		if (collidingOrganism->checkIfAlive() && collidingOrganism->getStrength() != strength) {
			collidingOrganism->collision(this);
		}
	}
	else if (collidingOrganism->checkIfAlive() && collidingOrganism->getImage() == image) {
		tryToBreed(collidingOrganism);
		return;
	}
	
}
Antelope::~Antelope() {

}