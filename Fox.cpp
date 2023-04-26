#include "Fox.h"

Fox::Fox(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = FOX_STRENGTH;
	initiative = FOX_INITIATIVE;
	image = FOX_IMAGE;
}
Organism* Fox::createChild(int xPosition, int yPosition) const {
	Organism* newFox = new Fox(xPosition, yPosition, currentWorld);
	return newFox;
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
bool Fox::checkIfAnyMovePossible() {
	if ((currentWorld->checkFieldXY(x - speed, y) && currentWorld->getOrganismFromXY(x - speed, y).getStrength() < strength) || (currentWorld->checkFieldXY(x + speed, y) && currentWorld->getOrganismFromXY(x + speed, y).getStrength() < strength) || (currentWorld->checkFieldXY(x, y - speed) && currentWorld->getOrganismFromXY(x, y - speed).getStrength() < strength) || (currentWorld->checkFieldXY(x, y + speed) && currentWorld->getOrganismFromXY(x, y + speed).getStrength() < strength)) {
		return true;
	}
	else if ((!currentWorld->checkFieldXY(x - speed, y) && x - 1 >= 0) || (!currentWorld->checkFieldXY(x + speed, y) && x + speed < currentWorld->getBoardSizeX()) || (!currentWorld->checkFieldXY(x, y - speed) && y - speed >= 0) || (!currentWorld->checkFieldXY(x, y + speed) && y + speed < currentWorld->getBoardSizeX())) {
		return true;
	}
	return false;
}
void Fox::action() {
	if (checkIfAnyMovePossible()) {
		direction moveDirection;
		if (checkIfAnyMovePossible()) {
			while (true) {
				moveDirection = (direction)(rand() % 4);
				if (checkMove(moveDirection)) {
					if (checkField(moveDirection)) {
						setMoveDirection(moveDirection);
						baseMovement();
						break;
					}
				}
			}
		}
	}
}
Fox::~Fox() {

}