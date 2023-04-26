#include "Turtle.h"

Turtle::Turtle(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = TURTLE_STRENGTH;
	initiative = TURTLE_INITIATIVE;
	image = TURTLE_IMAGE;
}
void Turtle::action() {
	int chanceToMove = rand() % 4;
	if (chanceToMove == 0) {
		Animal::action();
	}
}
Organism* Turtle::createChild(int xPosition, int yPosition) const {
	Organism* newTurtle = new Turtle(xPosition, yPosition, currentWorld);
	return newTurtle;
}
void Turtle::collision(Organism* collidingOrganism) {
	if (image == collidingOrganism->getImage()) {
		tryToBreed(collidingOrganism);
		return;
	}
	if (collidingOrganism->getStrength() < 5 && currentWorld->checkIfAnimal(collidingOrganism->getX(), collidingOrganism->getY())) {
		Animal* collidingAnimal = dynamic_cast<Animal*>(collidingOrganism);
		if (collidingAnimal->getMoveDirection() == UP) {
			collidingAnimal->setMoveDirection(DOWN);
		}
		else if (collidingAnimal->getMoveDirection() == DOWN) {
			collidingAnimal->setMoveDirection(UP);
		}
		else if (collidingAnimal->getMoveDirection() == RIGHT) {
			collidingAnimal->setMoveDirection(LEFT);
		}
		else if (collidingAnimal->getMoveDirection() == LEFT) {
			collidingAnimal->setMoveDirection(RIGHT);
		}
		string* info = new string("Zolw o wspolrzednych: ");
		char* tmpX = new char[2];
		_itoa(x, tmpX, 10);
		string* x = new string(tmpX);
		info->append(*x);
		info->append(", ");
		char* tmpY = new char[2];
		_itoa(y, tmpY, 10);
		string* y = new string(tmpY);
		info->append(*y);
		info->append(" odpiera atak");
		currentWorld->addEventsInfo(*info);
	}
	else {
		baseFight(collidingOrganism);
		if (collidingOrganism->checkIfAlive() && collidingOrganism->getStrength() != strength) {
			collidingOrganism->collision(this);
		}
	}
}
Turtle::~Turtle() {

}