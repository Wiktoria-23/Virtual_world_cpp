#include "World.h"
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

World::World(int xSize, int ySize) : roundCounter(NULL), boardX(xSize), boardY(ySize) {
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
	coordinates newCoordinates = *getEmptyField();
	Human* newHuman = new Human(newCoordinates.x, newCoordinates.y);
	allOrganisms.push_back(newHuman);
	sortOrganisms();
}
void World::performRound() {
	for (int i = 0; i < allOrganisms.size(); i++) {
		allOrganisms[i]->action();
	}
}
char World::getImageXY(int x, int y) {
	int organismsAmount = allOrganisms.size();
	for (int i = 0; i < organismsAmount; i++) {
		if (allOrganisms[i]->getX() == x && allOrganisms[i]->getY() == y) {
			return allOrganisms[i]->getImage();
		}
	}
	return EMPTY;
}
bool World::checkFieldXY(int x, int y) {
	int organismsAmount = allOrganisms.size();
	for (int i = 0; i < organismsAmount; i++) {
		if (allOrganisms[i]->getX() == x && allOrganisms[i]->getY() == y) {
			return true;
		}
	}
	return false;
}
void World::printWorld() {
	system("cls");
	cout << "Wiktoria Kubacka 193370" << endl << endl;
	for (int x = 0; x < boardX; x++) {
		cout << "__";
	}
	cout << endl;
	for (int y = 0; y < boardY; y++) {
		for (int x = 0; x < boardX; x++) {
			cout << "|";
			cout << getImageXY(x, y);
		}
		cout << '|' << endl;
	}
	cout << endl;
}
int World::getRoundCounter() {
	return roundCounter;
}
void World::incrementRoundCounter() {
	roundCounter += 1;
}
coordinates* World::getEmptyField() {
	coordinates newCoordinates = { rand() % boardX, rand() % boardY };
	while (checkFieldXY(newCoordinates.x, newCoordinates.y)) {
		newCoordinates = { rand() % boardX, rand() % boardY };
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