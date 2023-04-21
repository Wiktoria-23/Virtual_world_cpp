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
void Turtle::collision(Organism* collidingOrganism) const {
	
}
Turtle::~Turtle() {

}