#include "Organism.h"

Organism::Organism(int xPosition, int yPosition, World* newWorld) : x(xPosition), y(yPosition), currentWorld(newWorld), age(NULL) {

}
int Organism::getStrength() const {
	return strength;
}
int Organism::getInitiative() const {
	return initiative;
}
int Organism::getX() const {
	return x;
}
int Organism::getY() const {
	return y;
}
char Organism::getImage() const {
	return image;
}
int Organism::getAge() const {
	return age;
}
bool Organism::checkCollision() const {
	if (currentWorld->checkFieldXY(x, y)) {
		return true;
	}
	return false;
}
//Organism* Organism::createChild(int xPosition, int yPosition) const {
//
//}
Organism::~Organism() {

}