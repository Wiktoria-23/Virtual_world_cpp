#include "Fox.h"

Fox::Fox(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = 3;
	initiative = 7;
	image = 'L';
}
bool Fox::checkField(direction moveDirection) {
	if (moveDirection == LEFT) {
		if (currentWorld->checkFieldXY(x - speed, y)) {
			if (currentWorld->getOrganismFromXY(x - speed, y).getStrength() > strength) {
				return false;
			}
		}
		return true;
	}
	else if (moveDirection == RIGHT) {
		if (currentWorld->checkFieldXY(x + speed, y)) {
			if (currentWorld->getOrganismFromXY(x + speed, y).getStrength() > strength) {
				return false;
			}
		}
		return true;
	}
	else if (moveDirection == UP) {
		if (currentWorld->checkFieldXY(x, y - speed)) {
			if (currentWorld->getOrganismFromXY(x, y - speed).getStrength() > strength) {
				return false;
			}
		}
		return true;
	}
	else if (moveDirection == DOWN) {
		if (currentWorld->checkFieldXY(x, y + speed)) {
			if (currentWorld->getOrganismFromXY(x, y + speed).getStrength() > strength) {
				return false;
			}
		}
		return true;
	}
}
void Fox::action() {
	direction moveDirection;
	while (true) {
		moveDirection = (direction)(rand() % 4);
		if (checkMove(moveDirection)) {
			if (checkField(moveDirection)) {
				break;
			}
		}
	}
	baseMovement(moveDirection);
}
Fox::~Fox() {

}