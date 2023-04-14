#include "Turtle.h"

Turtle::Turtle(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = 2;
	initiative = 1;
	image = 'Z';
}
void Turtle::action() {
	int chanceToMove = rand() % 4;
	if (chanceToMove == 0) {
		Animal::action();
	}
}
void Turtle::collision() {
	
}
Turtle::~Turtle() {

}