#include "Human.h"

Human::Human(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = HUMAN_STRENGTH;
	initiative = HUMAN_INITIATIVE;
	superpowerActive = false;
	image = HUMAN_IMAGE;
	moveDirection = (direction)NONE;
}
void Human::action() {
	if (moveDirection != NONE && checkMove(moveDirection)) {
		baseMovement();
	}
	moveDirection = (direction)NONE;
}
void Human::collision(Organism* collidingOrganism) {
	if (superpowerActive) {

	}
	else {

	}
}
Organism* Human::createChild(int xPosition, int yPosition) const {
	return nullptr;
}
Human::~Human() {

}