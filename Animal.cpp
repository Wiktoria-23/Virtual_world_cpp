#include "Animal.h"

void Animal::action() {
	direction moveDirection = (direction)(rand() % 4);
	if (moveDirection == LEFT) {
		x -= 1;
	}
	else if (moveDirection == RIGHT) {
		x += 1;
	}
	else if (moveDirection == UP) {
		y += 1;
	}
	else if (moveDirection == DOWN) {
		y -= 1;
	}
}
void Animal::collision() {

}