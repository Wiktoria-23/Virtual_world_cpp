#include <math.h>
#include "Organism.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Nightshade.h"
#include "SosnowskyHogweed.h"
#include "Human.h"

World::World(int xSize, int ySize) : roundCounter(NULL), boardSizeX(xSize), boardSizeY(ySize) {
	createOrganisms<Wolf>();
	createOrganisms<Sheep>();
	createOrganisms<Fox>();
	createOrganisms<Turtle>();
	createOrganisms<Antelope>();
	createOrganisms<Grass>();
	createOrganisms<Dandelion>();
	createOrganisms<Guarana>();
	createOrganisms<Nightshade>();
	createOrganisms<SosnowskyHogweed>();
	coordinates newCoordinates = *getRandomEmptyField();
	Human* newHuman = new Human(newCoordinates.x, newCoordinates.y, this);
	allOrganisms.push_back(newHuman);
	sortOrganisms();
}
int World::randOrganismsAmount() {
	float field = boardSizeX * boardSizeY;
	int maxOccupied = ceil(field / 100 * 3); // setting maxOccupied field by organism type to 3% of whole field
	return rand() % maxOccupied + 1; //cannot return 0
}
void World::performRound() {
	for (int i = 0; i < allOrganisms.size(); i++) {
		allOrganisms[i]->action();
		if (allOrganisms[i]->checkCollision()) {
			allOrganisms[i]->collision();
		}
	}
}
char World::getImageXY(int x, int y) const {
	int organismsAmount = allOrganisms.size();
	for (int i = 0; i < organismsAmount; i++) {
		if (allOrganisms[i]->getX() == x && allOrganisms[i]->getY() == y) {
			return allOrganisms[i]->getImage();
		}
	}
	return EMPTY;
}
bool World::checkFieldXY(int x, int y) const {
	int organismsAmount = allOrganisms.size();
	for (int i = 0; i < organismsAmount; i++) {
		if (allOrganisms[i]->getX() == x && allOrganisms[i]->getY() == y) {
			return true;
		}
	}
	return false;
}
int World::getBoardSizeX() const {
	return boardSizeX;
}
int World::getBoardSizeY() const {
	return boardSizeY;
}
Organism& World::getOrganismFromXY(int x, int y) {
	for (int i = 0; i < allOrganisms.size(); i++) {
		if (allOrganisms[i]->getX() == x && allOrganisms[i]->getY() == y) {
			return *allOrganisms[i];
		}
	}
}
void World::printWorld() const {
	system("cls");
	cout << "Wiktoria Kubacka 193370" << endl << endl;
	for (int x = 0; x < boardSizeX; x++) {
		cout << "__";
	}
	cout << endl;
	for (int y = 0; y < boardSizeY; y++) {
		for (int x = 0; x < boardSizeY; x++) {
			cout << "|";
			cout << getImageXY(x, y);
		}
		cout << '|' << endl;
	}
	cout << endl;
}
int World::getRoundCounter() const {
	return roundCounter;
}
void World::incrementRoundCounter() {
	roundCounter += 1;
}
coordinates* World::getRandomEmptyField() const {
	coordinates newCoordinates = { rand() % boardSizeX, rand() % boardSizeY };
	while (checkFieldXY(newCoordinates.x, newCoordinates.y)) {
		newCoordinates = { rand() % boardSizeX, rand() % boardSizeY };
	}
	return &newCoordinates;
}
void World::sortOrganisms() {
	int i = 0;
	for (int j = i; j < allOrganisms.size(); j++) {
		int highestInitiative = NULL;
		for (int k = i; k < allOrganisms.size(); k++) {
			if (allOrganisms[k]->getInitiative() > highestInitiative) {
				highestInitiative = allOrganisms[k]->getInitiative();
			}
		}
		int highestAge = NULL;
		for (int l = i; l < allOrganisms.size(); l++) {
			if (allOrganisms[l]->getInitiative() == highestInitiative && allOrganisms[l]->getAge() > highestAge) {
				highestAge = allOrganisms[l]->getAge();
			}
		}
		int m = i;
		while (allOrganisms[m]->getInitiative() != highestInitiative && allOrganisms[m]->getAge() == highestAge) {
			m++;
		}
		allOrganisms.insert(allOrganisms.begin() + i, allOrganisms[m]);
		allOrganisms.erase(allOrganisms.begin() + m + 1);
		i++;
	}
}
World::~World() {

}