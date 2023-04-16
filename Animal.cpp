#include "Animal.h"

Animal::Animal(int xPosition, int yPosition, World* newWorld) : Organism(xPosition, yPosition, newWorld) {
	moveDirection = NONE;
}
void Animal::baseMovement() {
	if (moveDirection == LEFT) {
		x -= speed;
	}
	else if (moveDirection == RIGHT) {
		x += speed;
	}
	else if (moveDirection == UP) {
		y -= speed;
	}
	else if (moveDirection == DOWN) {
		y += speed;
	}
}
void Animal::setMoveDirection(direction newMoveDirection) {
	if (this->checkMove(newMoveDirection)) {
		moveDirection = newMoveDirection;
	}
	else {
		moveDirection = (direction)NONE;
	}
}
bool Animal::checkMove(direction newMoveDirection) {
	int tmpX = x;
	int tmpY = y;
	if (newMoveDirection == LEFT) {
		tmpX -= speed;
	}
	else if (newMoveDirection == RIGHT) {
		tmpX += speed;
	}
	else if (newMoveDirection == UP) {
		tmpY -= speed;
	}
	else if (newMoveDirection == DOWN) {
		tmpY += speed;
	}
	if (tmpX >= 0 && tmpX < currentWorld->getBoardSizeX() && tmpY >= 0 && tmpY < currentWorld->getBoardSizeY()) {
		return true;
	}
	return false;
}
void Animal::action() {
	while (true) {
		moveDirection = (direction)(rand() % 4);
		if (checkMove(moveDirection)) {
			Organism* collidingOrganism = getCollision(moveDirection);
			if (collidingOrganism != nullptr) {
				collision(collidingOrganism);
			}
			baseMovement();
			break;
		}
	}
}
void Animal::collision(Organism* collidingOrganism) {
	//dodaj obs³ugê kolizji
}
Organism* Animal::getCollision(direction moveDirection) {
	if (moveDirection == UP) {
		if (currentWorld->checkFieldXY(x, y - 1)) {
			Organism* collidingOrganism = &currentWorld->getOrganismFromXY(x, y - 1);
			return collidingOrganism;
		}
	}
	else if (moveDirection == DOWN) {
		if (currentWorld->checkFieldXY(x, y + 1)) {
			Organism* collidingOrganism = &currentWorld->getOrganismFromXY(x, y + 1);
			return collidingOrganism;
		}
	}
	else if (moveDirection == RIGHT) {
		if (currentWorld->checkFieldXY(x + 1, y)) {
			Organism* collidingOrganism = &currentWorld->getOrganismFromXY(x + 1, y);
			return collidingOrganism;
		}
	}
	else if (moveDirection == LEFT) {
		if (currentWorld->checkFieldXY(x - 1, y)) {
			Organism* collidingOrganism = &currentWorld->getOrganismFromXY(x - 1, y);
			return collidingOrganism;
		}
	}
	else {
		return nullptr;
	}
}