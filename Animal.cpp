#include "Animal.h"

Animal::Animal(int xPosition, int yPosition, World* newWorld) : Organism(xPosition, yPosition, newWorld) {
}
void Animal::baseMovement(direction moveDirection) {
	if (moveDirection == LEFT) {
		x -= speed;
	}
	else if (moveDirection == RIGHT) {
		x += speed;
	}
	else if (moveDirection == UP) {
		y += speed;
	}
	else if (moveDirection == DOWN) {
		y -= speed;
	}
}
void Animal::action() {
	direction moveDirection = (direction)(rand() % 4);//dodaæ brak mo¿liwoœci wychodzenia poza planszê
	baseMovement(moveDirection);
}
void Animal::collision() {

}