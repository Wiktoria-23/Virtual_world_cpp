#include "Turtle.h"

Turtle::Turtle(int xPosition, int yPosition) {
	strength = 2;
	initiative = 1;
	image = 'Z';
	x = xPosition;
	y = yPosition;
}
void Turtle::action() {
	//move every fourth round
}
void Turtle::collision() {

}
Turtle::~Turtle() {

}