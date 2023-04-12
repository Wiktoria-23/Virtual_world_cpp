#include "Animal.h"

void Animal::action() {
	direction moveDirection = (direction)(rand() % 4);
	if (moveDirection == LEFT) {
		x -= 2;
	}
	else if (moveDirection == RIGHT) {
		x += 2;
	}
	else if (moveDirection == UP) {
		y += 2;
	}
	else if (moveDirection == DOWN) {
		y -= 2;
	}
}
void Animal::collision() {

}