#include "Animal.h"

Animal::Animal(int xPosition, int yPosition, World* newWorld) : Organism(xPosition, yPosition, newWorld) {
}
void Animal::baseMovement(direction moveDirection) {
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
bool Animal::checkMove(direction moveDirection) {
	int tmpX = x;
	int tmpY = y;
	if (moveDirection == LEFT) {
		tmpX -= speed;
	}
	else if (moveDirection == RIGHT) {
		tmpX += speed;
	}
	else if (moveDirection == UP) {
		tmpY -= speed;
	}
	else if (moveDirection == DOWN) {
		tmpY += speed;
	}
	if (tmpX >= 0 && tmpX < currentWorld->getBoardSizeX() && tmpY >= 0 && tmpY < currentWorld->getBoardSizeY()) {
		return true;
	}
	return false;
}
void Animal::action() {
	while (true) {
		direction moveDirection = (direction)(rand() % 4);
		if (checkMove(moveDirection)) {
			baseMovement(moveDirection);
			break;
		}
	}
}
void Animal::collision() {

}