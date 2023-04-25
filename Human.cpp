#include "Human.h"

Human::Human(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	roundCounter = 0;
	strength = HUMAN_STRENGTH;
	initiative = HUMAN_INITIATIVE;
	superpowerActive = false;
	image = HUMAN_IMAGE;
	moveDirection = (direction)NONE;
}
void Human::action() {
	if (superpowerActive) {
		string* info = new string("Super umiejetnosc czlowieka aktywna");
		currentWorld->addEventsInfo(info);
		if (roundCounter == 0) {
			superpowerActive = false;
			roundCounter = 5;
		}
	}
	else {
		string* info = new string("Super umiejetnosc czlowieka nie aktywna");
		currentWorld->addEventsInfo(info);
	}
	if (moveDirection != NONE && checkMove(moveDirection)) {
		Organism* collidingOrganism = getCollision(moveDirection);
		if (collidingOrganism != nullptr && collidingOrganism->checkIfAlive()) {
			collision(collidingOrganism);
		}
		baseMovement();
	}
	moveDirection = (direction)NONE;
	if (roundCounter > 0) {
		roundCounter -= 1;
	}
}
bool Human::canSuperpowerBeActivated() {
	if (roundCounter == 0 && !superpowerActive) {
		return true;
	}
	return false;
}
void Human::collision(Organism* collidingOrganism) {
	if (superpowerActive && collidingOrganism->getStrength() > strength) {
			direction moveDirection = (direction)(rand() % 4);
			setMoveDirection(moveDirection);
			baseMovement();
	}
	else {
		Organism::collision(collidingOrganism);
	}
}
void Human::setDeadState() {
	if (superpowerActive == false) {
		alive = false;
	}
}
bool Human::superpowerState() {
	return superpowerActive;
}
void Human::activateSuperpower() {
	roundCounter = 5;
	superpowerActive = true;//dodaj licznik rund
}
Organism* Human::createChild(int xPosition, int yPosition) const {
	return nullptr;
}
Human::~Human() {

}