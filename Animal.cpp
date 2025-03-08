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
bool Animal::checkMove(direction newMoveDirection) const {
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
			if (collidingOrganism != nullptr && collidingOrganism->checkIfAlive()) {
				collision(collidingOrganism);
			}
			else {
				baseMovement();
			}
			break;
		}
		break;
	}
}
direction Animal::getMoveDirection() {
	return moveDirection;
}
void Animal::breed(int xPosition, int yPosition) const {
	Organism* newAnimal = createChild(xPosition, yPosition);
	currentWorld->addOrganism(newAnimal);
}
bool Animal::checkSameType(Organism* collidingOrganism) const {
	if (image == collidingOrganism->getImage()) {
		return true;
	}
	return false;
}
void Animal::tryToBreed(Organism* collidingOrganism) const{
	if (
		(currentWorld->checkFieldXY(x, y - 1) && currentWorld->getOrganismFromXY(x, y - 1).getImage()) != image
		|| (currentWorld->checkFieldXY(x, y + 1) && currentWorld->getOrganismFromXY(x, y + 1).getImage() != image)
		|| (currentWorld->checkFieldXY(x - 1, y) && currentWorld->getOrganismFromXY(x - 1, y).getImage() != image)
		|| (currentWorld->checkFieldXY(x + 1, y) && currentWorld->getOrganismFromXY(x + 1, y).getImage() != image)
		) {
		direction breedDirection = (direction)(rand() % 4);
		if (breedDirection == DOWN && y + 1 < currentWorld->getBoardSizeY() && y + 1 != collidingOrganism->getY()) {
			if (
				(currentWorld->checkFieldXY(x, y + 1) && currentWorld->getOrganismFromXY(x, y + 1).getImage() != image
				&& currentWorld->getOrganismFromXY(x, y + 1).getAge() > 0) || !currentWorld->checkFieldXY(x, y + 1)
				) {
				breed(x, y + 1);
				currentWorld->addAnimalBreedInfo(*this);
			}
		}
		else if (breedDirection == UP && y - 1 >= 0 && y - 1 != collidingOrganism->getY()) {
			if (
				(currentWorld->checkFieldXY(x, y - 1) && currentWorld->getOrganismFromXY(x, y - 1).getImage() != image
				&& currentWorld->getOrganismFromXY(x, y - 1).getAge() > 0) || !currentWorld->checkFieldXY(x, y - 1)
				) {
				breed(x, y - 1);
				currentWorld->addAnimalBreedInfo(*this);
			}
		}
		else if (breedDirection == RIGHT && x + 1 < currentWorld->getBoardSizeX() && x + 1 != collidingOrganism->getX()) {
			if (
				(currentWorld->checkFieldXY(x + 1, y) && currentWorld->getOrganismFromXY(x + 1, y).getImage() != image
				&& currentWorld->getOrganismFromXY(x + 1, y).getAge() > 0) || !currentWorld->checkFieldXY(x + 1, y)
				) {
				breed(x + 1, y);
				currentWorld->addAnimalBreedInfo(*this);
			}
		}
		else if (breedDirection == LEFT && x - 1 >= 0 && x - 1 != collidingOrganism->getX()) {
			if (
				(currentWorld->checkFieldXY(x - 1, y) && currentWorld->getOrganismFromXY(x - 1, y).getImage() != image
				&& currentWorld->getOrganismFromXY(x - 1, y).getAge() > 0) || !currentWorld->checkFieldXY(x - 1, y)
				) {
				breed(x - 1, y);
				currentWorld->addAnimalBreedInfo(*this);
			}
		}
	}
}
void Animal::collision(Organism* collidingOrganism) {
	if (image == collidingOrganism->getImage()) {
		tryToBreed(collidingOrganism);
		return;
	}
	else if (collidingOrganism->checkIfAlive() && collidingOrganism->getStrength() != strength) {
		Organism::collision(collidingOrganism);
	}
	baseMovement();
}