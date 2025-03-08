#include "Organism.h"

Organism::Organism(
	int xPosition, int yPosition, World* newWorld
	) : x(xPosition), y(yPosition), currentWorld(newWorld), age(NULL), alive(true) {
}
Organism* Organism::getCollision(direction moveDirection) {
	Organism* collidingOrganism = nullptr;
	if (moveDirection == UP) {
		if (currentWorld->checkFieldXY(x, y - 1)) {
			collidingOrganism = &currentWorld->getOrganismFromXY(x, y - 1);
		}
	}
	else if (moveDirection == DOWN) {
		if (currentWorld->checkFieldXY(x, y + 1)) {
			collidingOrganism = &currentWorld->getOrganismFromXY(x, y + 1);
		}
	}
	else if (moveDirection == RIGHT) {
		if (currentWorld->checkFieldXY(x + 1, y)) {
			collidingOrganism = &currentWorld->getOrganismFromXY(x + 1, y);
		}
	}
	else if (moveDirection == LEFT) {
		if (currentWorld->checkFieldXY(x - 1, y)) {
			collidingOrganism = &currentWorld->getOrganismFromXY(x - 1, y);
		}
	}
	if (collidingOrganism != nullptr && collidingOrganism->checkIfAlive()) {
		return collidingOrganism;
	}
	else {
		return nullptr;
	}
}
void Organism::setDeadState() {
	alive = false;
}
bool Organism::checkIfAlive() const {
	return alive;
}
void Organism::increaseStrength(int amount) {
	strength += amount;
}
void Organism::collision(Organism* collidingOrganism) {
	baseFight(collidingOrganism);
	if (collidingOrganism->checkIfAlive() && alive) {
		collidingOrganism->collision(this);
	}
}
void Organism::baseFight(Organism* collidingOrganism) {
	if (collidingOrganism->strength > strength) {
		setDeadState();
		currentWorld->addDeathInfo(*this, *collidingOrganism);
	}
}
void Organism::setStrength(int newStrength) {
	strength = newStrength;
}
void Organism::setInitiative(int newInitiative) {
	initiative = newInitiative;
}
void Organism::setAge(int newAge) {
	age = newAge;
}
void Organism::setAliveState(bool newAlive) {
	alive = newAlive;
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