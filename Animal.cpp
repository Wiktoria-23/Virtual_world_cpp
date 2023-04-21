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
			baseMovement();
			if (collidingOrganism != nullptr) {
				collision(collidingOrganism);
			}
			break;
		}
	}
}
direction Animal::getMoveDirection() {
	return moveDirection;
}
bool Animal::checkSameType(Organism* collidingOrganism) {
	if (image == collidingOrganism->getImage()) {
		return true;
	}
	return false;
}
void Animal::collision(Organism* collidingOrganism) {
	if (image != collidingOrganism->getImage()) {
		baseFight(collidingOrganism);
		if (collidingOrganism->checkIfAlive()) {
			collidingOrganism->collision(this);
		}
	}
	else {
		//rozmnazanie
	}
}