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
	int amount = countOrganismsAmount();
	for (int i = 0; i < amount; i++) {
		createOrganism<Wolf>();
		createOrganism<Sheep>();
		createOrganism<Fox>();
		createOrganism<Turtle>();
		createOrganism<Antelope>();
		createOrganism<Grass>();
		createOrganism<Dandelion>();
		createOrganism<Guarana>();
		createOrganism<Nightshade>();
		createOrganism<SosnowskyHogweed>();
	}
	createOrganism<Human>();
	sortOrganisms();
	string* info = new string("Stworzono wszystkie organizmy");
	addEventsInfo(info);
}
void World::addEventsInfo(string* newInfo) {
	allEventsInfo.push_back(newInfo);
}
int World::countOrganismsAmount() {
	float field = boardSizeX * boardSizeY;
	int maxOccupied = ceil(field / 100 * 2); // setting maxOccupied field by organism type to 2% of whole field
	return maxOccupied + 1;
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
			if (allOrganisms[i]->getImage() == HUMAN_IMAGE) {
				Human* humanPointer = dynamic_cast<Human*>(allOrganisms[i]);
				if (!humanPointer->superpowerState()) {
					allOrganisms.erase(allOrganisms.begin() + i);
					delete tmp;
				}
			}
			else {
				allOrganisms.erase(allOrganisms.begin() + i);
				delete tmp;
			}
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
void World::addPlantGrowInfo(const Organism& parent) {
	string* info = new string("Roslina ");
	char* img = new char[2];
	img[0] = parent.getImage();
	img[1] = '\0';
	info->append(img);
	info->append(" o wspolrzednych: ");
	char* tmpX = new char[2];
	_itoa(parent.getX(), tmpX, 10);
	string* x = new string(tmpX);
	info->append(*x);
	info->append(", ");
	char* tmpY = new char[2];
	_itoa(parent.getY(), tmpY, 10);
	string* y = new string(tmpY);
	info->append(*y);
	info->append(" rozrosla sie");
	addEventsInfo(info);
}
void World::addAnimalBreedInfo(const Organism& parent) {
	string* info = new string("Zwierze ");
	char* img = new char[2];
	img[0] = parent.getImage();
	img[1] = '\0';
	info->append(img);
	info->append(" o wspolrzednych: ");
	char* tmpX = new char[2];
	_itoa(parent.getX(), tmpX, 10);
	string* x = new string(tmpX);
	info->append(*x);
	info->append(", ");
	char* tmpY = new char[2];
	_itoa(parent.getY(), tmpY, 10);
	string* y = new string(tmpY);
	info->append(*y);
	info->append(" rozmozylo sie");
	addEventsInfo(info);
}
void World::addDeathInfo(const Organism& deadOrganism, const Organism& killingOrganism) {
	string* info = new string("Organizm ");
	char* img = new char[2];
	img[0] = deadOrganism.getImage();
	img[1] = '\0';
	info->append(img);
	info->append(" o wspolrzednych: ");
	char* tmpX = new char[2];
	_itoa(deadOrganism.getX(), tmpX, 10);
	string* x = new string(tmpX);
	info->append(*x);
	info->append(", ");
	char* tmpY = new char[2];
	_itoa(deadOrganism.getY(), tmpY, 10);
	string* y = new string(tmpY);
	info->append(*y);
	info->append(" zostal zabity przez ");
	img[0] = killingOrganism.getImage();
	info->append(img);
	addEventsInfo(info);
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
		for (int x = 0; x < boardSizeX; x++) {
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
	for (int i = 0; i < boardSizeY && i < allEventsInfo.size(); i++) {
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