#include "Organism.h"

Organism::Organism(int xPosition, int yPosition, World* newWorld) : x(xPosition), y(yPosition), currentWorld(newWorld), age(NULL) {

}
Organism* Organism::getCollision(direction moveDirection) {
	if (moveDirection == UP) {
		if (currentWorld->checkFieldXY(x, y - 1)) {
			Organism* collidingOrganism = &currentWorld->getOrganismFromXY(x, y - 1);
			return collidingOrganism;
		}
	}
	else if (moveDirection == DOWN) {
		if (currentWorld->checkFieldXY(x, y + 1)) {
			Organism* collidingOrganism = &currentWorld->getOrganismFromXY(x, y + 1);
			return collidingOrganism;
		}
	}
	else if (moveDirection == RIGHT) {
		if (currentWorld->checkFieldXY(x + 1, y)) {
			Organism* collidingOrganism = &currentWorld->getOrganismFromXY(x + 1, y);
			return collidingOrganism;
		}
	}
	else if (moveDirection == LEFT) {
		if (currentWorld->checkFieldXY(x - 1, y)) {
			Organism* collidingOrganism = &currentWorld->getOrganismFromXY(x - 1, y);
			return collidingOrganism;
		}
	}
	else {
		return nullptr;
	}
}
void Organism::baseFight(Organism* collidingOrganism) const {
	if (collidingOrganism->strength < strength) {
		currentWorld->killOrganismFromXY(collidingOrganism->getX(), collidingOrganism->getY());
	}
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
void Organism::incrementAgeCounter() {
	age += 1;
}
Organism::~Organism() {

}