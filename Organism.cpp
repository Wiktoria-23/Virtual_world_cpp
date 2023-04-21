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
	if (collidingOrganism->strength > strength) {
		string* info = new string("Organizm ");
		char* img = new char[1];
		img[0] = getImage();
		img[1] = '\0';
		info->append(img);
		info->append(" o wspolrzednych: ");
		char* tmpX = new char[2];
		_itoa(getX(), tmpX, 10);
		string* x = new string(tmpX);
		info->append(*x);
		info->append(", ");
		char* tmpY = new char[2];
		_itoa(getY(), tmpY, 10);
		string* y = new string(tmpY);
		info->append(*y);
		info->append(" zostal zabity.");
		currentWorld->addEventsInfo(info);
		currentWorld->killOrganismFromXY(getX(), getY());
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