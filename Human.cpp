#include "Human.h"

Human::Human(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = 5;
	initiative = 4;
	superpowerActive = false;
	image = 'C';
}
void Human::action() {
	if (superpowerActive) {

	}
	else {

	}
}
void Human::collision() {

}
Human::~Human() {

}