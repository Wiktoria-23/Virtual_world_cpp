#include "Human.h"

Human::Human(int xPosition, int yPosition) {
	strength = 5;
	initiative = 4;
	superpowerActive = false;
	image = 'C';
	x = xPosition;
	y = yPosition;
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