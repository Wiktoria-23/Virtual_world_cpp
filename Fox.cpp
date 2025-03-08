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
bool Fox::checkField(direction moveDirection) const {
	if (moveDirection == LEFT) {
		if (currentWorld->checkFieldXY(x - speed, y)) {
			if (currentWorld->getOrganismFromXY(x - speed, y).getImage() == image) {
				return true;
			}
			if (currentWorld->getOrganismFromXY(x - speed, y).getStrength() > strength) {
				return false;
			}
		}
		return true;
	}
	else if (moveDirection == RIGHT) {
		if (currentWorld->checkFieldXY(x + speed, y)) {
			if (currentWorld->getOrganismFromXY(x + speed, y).getImage() == image) {
				return true;
			}
			if (currentWorld->getOrganismFromXY(x + speed, y).getStrength() > strength) {
				return false;
			}
		}
		return true;
	}
	else if (moveDirection == UP) {
		if (currentWorld->checkFieldXY(x, y - speed)) {
			if (currentWorld->getOrganismFromXY(x, y - speed).getImage() == image) {
				return true;
			}
			if (currentWorld->getOrganismFromXY(x, y - speed).getStrength() > strength) {
				return false;
			}
		}
		return true;
	}
	else if (moveDirection == DOWN) {
		if (currentWorld->checkFieldXY(x, y + speed)) {
			if (currentWorld->getOrganismFromXY(x, y + speed).getImage() == image) {
				return true;
			}
			if (currentWorld->getOrganismFromXY(x, y + speed).getStrength() > strength) {
				return false;
			}
		}
		return true;
	}
}
bool Fox::checkIfAnyMovePossible() const {
	if (x < 0 || x >= currentWorld->getBoardSizeX() || y < 0 || y >= currentWorld->getBoardSizeY()) {
		return false;
	}
	if (
		(currentWorld->checkFieldXY(x - speed, y) && currentWorld->getOrganismFromXY(x - speed, y).getStrength() < strength)
		|| (currentWorld->checkFieldXY(x + speed, y) && currentWorld->getOrganismFromXY(x + speed, y).getStrength() < strength)
		|| (currentWorld->checkFieldXY(x, y - speed) && currentWorld->getOrganismFromXY(x, y - speed).getStrength() < strength)
		|| (currentWorld->checkFieldXY(x, y + speed) && currentWorld->getOrganismFromXY(x, y + speed).getStrength() < strength)
		) {
		return true;
	}
	if (
		(!currentWorld->checkFieldXY(x - speed, y) && x - 1 >= 0)
		|| (!currentWorld->checkFieldXY(x + speed, y) && x + speed < currentWorld->getBoardSizeX())
		|| (!currentWorld->checkFieldXY(x, y - speed) && y - speed >= 0)
		|| (!currentWorld->checkFieldXY(x, y + speed) && y + speed < currentWorld->getBoardSizeX())
		) {
		return true;
	}
	return false;
}
void Fox::action() {
	if (checkIfAnyMovePossible()) {
	direction moveDirection;
		while (true) {
			moveDirection = (direction)(rand() % 4);
			if (checkMove(moveDirection)) {
				if (checkField(moveDirection)) {
					Organism* collidingOrganism = getCollision(moveDirection);
					if (collidingOrganism != nullptr) {
						collision(collidingOrganism);
					}
					setMoveDirection(moveDirection);
					baseMovement();
					break;
				}
			}
		}
	}
}
Fox::~Fox() {

}