#include "Human.h"

Human::Human(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	roundCounter = 0;
	strength = HUMAN_STRENGTH;
	initiative = HUMAN_INITIATIVE;
	superpowerActive = false;
	image = HUMAN_IMAGE;
	moveDirection = (direction)NONE;
}
void Human::action() {
	if (roundCounter == 0 && superpowerActive) {
		superpowerActive = false;
		roundCounter = 5;
	}
	if (moveDirection != NONE && checkMove(moveDirection)) {
		baseMovement();
	}
	moveDirection = (direction)NONE;
	if (roundCounter > 0) {
		roundCounter -= 1;
	}
}
bool Human::canSuperpowerBeActivated() {
	if (roundCounter == 0 && !superpowerActive) {
		return true;
	}
	return false;
}
void Human::collision(Organism* collidingOrganism) {
	if (superpowerActive && collidingOrganism->getStrength() > strength) {
			direction moveDirection = (direction)(rand() % 4);
			setMoveDirection(moveDirection);
			baseMovement();
	}
	else {
		Animal::collision(collidingOrganism);
	}
}
void Human::activateSuperpower() {
	roundCounter = 5;
	superpowerActive = true;//dodaj licznik rund
}
Organism* Human::createChild(int xPosition, int yPosition) const {
	return nullptr;
}
Human::~Human() {

}