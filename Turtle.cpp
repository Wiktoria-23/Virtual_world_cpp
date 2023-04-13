#include "Turtle.h"

Turtle::Turtle(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = 2;
	initiative = 1;
	image = 'Z';
}
void Turtle::action() {
	//move every fourth round
}
void Turtle::collision() {

}
Turtle::~Turtle() {

}