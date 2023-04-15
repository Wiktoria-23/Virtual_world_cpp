#include "Human.h"

Human::Human(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = 5;
	initiative = 4;
	superpowerActive = false;
	image = 'C';
	moveDirection = (direction)NONE;
}
void Human::setMoveDirection(direction newMoveDirection) {
	if (this->checkMove(newMoveDirection)) {
		moveDirection = newMoveDirection;
	}
	else {
		moveDirection = (direction)NONE;
	}
}
void Human::action() {
	if (moveDirection != NONE) {
		baseMovement(moveDirection);
	}
	moveDirection = (direction)NONE;
}
void Human::collision() {
	if (superpowerActive) {

	}
	else {

	}
}
Human::~Human() {

}