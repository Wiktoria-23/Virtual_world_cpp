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
	for (int i = 0; i < 2; i++) {
		createOrganisms<Sheep>();
		createOrganisms<Wolf>();
		createOrganisms<Fox>();
		createOrganisms<Turtle>();
		createOrganisms<Antelope>();
	}
	createOrganisms<Grass>();
	createOrganisms<Dandelion>();
	createOrganisms<Guarana>();
	createOrganisms<Nightshade>();
	createOrganisms<SosnowskyHogweed>();
	coordinates newCoordinates = *getRandomEmptyField();
	Human* newHuman = new Human(newCoordinates.x, newCoordinates.y, this);
	allOrganisms.push_back(newHuman);
	sortOrganisms();
	string* info = new string("Stworzono wszystkie organizmy");
	addEventsInfo(info);
}
void World::addEventsInfo(string* newInfo) {
	allEventsInfo.push_back(newInfo);
}
int World::randOrganismsAmount() {
	float field = boardSizeX * boardSizeY;
	int maxOccupied = ceil(field / 100 * 3); // setting maxOccupied field by organism type to 3% of whole field
	return rand() % maxOccupied + 1; //cannot return 0
}
void World::performRound() {
	for (int i = 0; i < allOrganisms.size(); i++) {
		if (allOrganisms[i]->checkIfAlive()) {
			allOrganisms[i]->action();
			allOrganisms[i]->incrementAgeCounter();
		}
	}
	for (int i = allOrganisms.size() - 1; i >= 0; i--) {
		if (!allOrganisms[i]->checkIfAlive()) {
			Organism* tmp = allOrganisms[i];
			allOrganisms.erase(allOrganisms.begin() + i);//doda� informacj� o �mierci tutaj
			delete tmp;
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
	//if (x < 0 || x >= getBoardSizeX() || y < 0 || y >= getBoardSizeY()) {//if field is out of border it is treated as occupied
	//	return false;
	//}
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
bool World::checkIfAnimal(int xPosition, int yPosition) {
	Organism* neighbourOrganism;
	if (xPosition >= 0 && xPosition < boardSizeX && yPosition >= 0 && boardSizeY) {
		if (checkFieldXY(xPosition, yPosition)) {
			neighbourOrganism = &getOrganismFromXY(xPosition, yPosition);
		}
		else {
			neighbourOrganism = nullptr;
		}
		if (neighbourOrganism != nullptr) {
			Animal* animalPointer = dynamic_cast<Animal*>(neighbourOrganism);
			if (animalPointer != nullptr) {
				return true;
			}
		}
	}
	return false;
}
void World::printWorld() {
	setCursorPosition(0, 1);
	cout << "Wiktoria Kubacka 193370" << endl << endl;
	for (int x = 0; x < boardSizeX; x++) {
		setCursorPosition(x * 2, 3);
		cout << "__";
	}
	cout << endl;
	for (int y = 0; y < boardSizeY; y++) {
		for (int x = 0; x < boardSizeY; x++) {
			setCursorPosition(x * 2, y + 4);
			cout << "|";
			cout << getImageXY(x, y);
		}
		cout << '|' << endl;
	}
	cout << endl;
	int yPosition = 2;
	for (int i = 0; i < boardSizeY; i++) {
		setCursorPosition(2 * boardSizeX + 5, 2 + yPosition);
		yPosition += 1;
		cout << "                                                           ";
	}
	yPosition = 2;
	for (int i = 0; i < allEventsInfo.size(); i++) {
		if (!allEventsInfo[i]->empty()) {
			setCursorPosition(2 * boardSizeX + 5, 2 + yPosition);
			yPosition += 1;
			cout << *allEventsInfo[i];
		}
	}
	for (int i = 0; i < allEventsInfo.size(); i++) {
		string* tmp = allEventsInfo[i];
		delete tmp;
	}
	allEventsInfo.clear();
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
Human* World::getHuman() {
	for (int i = 0; i < allOrganisms.size(); i++) {
		Human* humanPointer = dynamic_cast<Human*>(allOrganisms[i]);
		if (humanPointer != nullptr) {
			return humanPointer;
		}
	}
	return nullptr;
}
void World::addOrganism(Organism* newOrganism) {
	allOrganisms.insert(allOrganisms.begin(), newOrganism);
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
void World::setCursorPosition(int xPosition, int yPosition) {
	cursorCoordinates.X = xPosition;
	cursorCoordinates.Y = yPosition;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorCoordinates);
}
World::~World() {

}