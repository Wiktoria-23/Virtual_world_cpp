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
		createOrganism<Sheep>();
		createOrganism<Fox>();
		createOrganism<Turtle>();
		createOrganism<Wolf>();
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
	addEventsInfo(*info);
}
void World::addEventsInfo(string& newInfo) {
	allEventsInfo.push_back(&newInfo);
}
int World::countOrganismsAmount() const {
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
	addEventsInfo(*info);
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
	addEventsInfo(*info);
}
void World::addDeathInfo(const Organism& deadOrganism, const Organism& killingOrganism) {
	if (!deadOrganism.checkIfAlive()) {
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
		addEventsInfo(*info);
	}
}
int World::getBoardSizeX() const {
	return boardSizeX;
}
int World::getBoardSizeY() const {
	return boardSizeY;
}
Organism& World::getOrganismFromXY(int x, int y) const {
	for (int i = 0; i < allOrganisms.size(); i++) {
		if (allOrganisms[i]->getX() == x && allOrganisms[i]->getY() == y) {
			return *allOrganisms[i];
		}
	}
}
bool World::checkIfAnimal(int xPosition, int yPosition) const {
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
	system("cls");
	setCursorPosition(0, 1);
	cout << "Wiktoria Kubacka 193370" << endl << endl;
	cout << "Aby poruszac sie uzywaj strzalek, ";
     cout << "x - aktywacja specjalnej umiejetnosci czlowieka, z - zapisz, w - wczytaj z pliku";
	for (int x = 0; x < boardSizeX; x++) {
		setCursorPosition(x + 1, 4);
		cout << "_";
	}
	cout << endl;
	for (int y = 0; y < boardSizeY; y++) {
		cout << '|' << endl;
		for (int x = 0; x < boardSizeX; x++) {
			setCursorPosition(x + 1, y + BOARD_START_Y);
			cout << getImageXY(x, y);
		}
		cout << '|' << endl;
	}
	cout << endl;
	int yPosition = 0;
	for (int i = 0; i < boardSizeY && i < allEventsInfo.size(); i++) {
		if (!allEventsInfo[i]->empty()) {
			setCursorPosition(boardSizeX + INFO_START_X, BOARD_START_Y + yPosition);
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
	coordinates newCoordinates;
	while (true) {
		newCoordinates = { rand() % boardSizeX, rand() % boardSizeY };
		if (!checkFieldXY(newCoordinates.x, newCoordinates.y)
			&& !checkFieldXY(newCoordinates.x - 1, newCoordinates.y)
			&& !checkFieldXY(newCoordinates.x + 1, newCoordinates.y)
			&& !checkFieldXY(newCoordinates.x, newCoordinates.y - 1)
			&& !checkFieldXY(newCoordinates.x, newCoordinates.y + 1)) {
			break;
		}
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
	allOrganisms.insert(allOrganisms.end(), newOrganism);
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
			if (allOrganisms[l]->getInitiative() == highestInitiative
				&& allOrganisms[l]->getAge() > highestAge) {
				highestAge = allOrganisms[l]->getAge();
			}
		}
		int m = i;
		while (
			allOrganisms[m]->getInitiative() != highestInitiative
			&& allOrganisms[m]->getAge() == highestAge
			) {
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
void World::save(string& filename) const {
	fstream file;
	file.open(filename, fstream::out);
	file << boardSizeX << endl;
	file << boardSizeY << endl;
	file << allOrganisms.size() << endl;
	for (int i = 0; i < allOrganisms.size(); i++) {

		file << allOrganisms[i]->getImage() << endl << allOrganisms[i]->checkIfAlive() << endl;
		file << allOrganisms[i]->getAge() << endl << allOrganisms[i]->getInitiative() << endl;
		file << allOrganisms[i]->getStrength() << endl << allOrganisms[i]->getX() << endl;
		file << allOrganisms[i]->getY() << endl;

		if (allOrganisms[i]->getImage() == HUMAN_IMAGE) {
			Human* humanPointer = dynamic_cast<Human*>(allOrganisms[i]);
			file << humanPointer->superpowerState() << endl << humanPointer->getRoundCounter() << endl;
		}
	}
	file.close();
}
void World::loadFromFile(string& filename) {
	fstream file;
	file.open(filename, fstream::in);
	if (file.is_open()) {
		for (int i = allOrganisms.size() - 1; i >= 0; i--) {
			Organism* tmp = allOrganisms[i];
			allOrganisms.erase(allOrganisms.begin() + i);
			delete tmp;
		}
		int amountOfOrganisms;
		file >> boardSizeX;
		file >> boardSizeY;
		file >> amountOfOrganisms;
		char organismImage;
		bool alive, superpowerActive;
		int age, initiative, strength, x, y, roundCount;
		for (int i = 0; i < amountOfOrganisms; i++) {
			file >> organismImage >> alive >> age >> initiative >> strength >> x >> y;
			Organism* newOrganism = nullptr;
			if (organismImage == ANTELOPE_IMAGE) {
				newOrganism = new Antelope(x, y, this);
			}
			else if (organismImage == DANDELION_IMAGE) {
				newOrganism = new Dandelion(x, y, this);
			}
			else if (organismImage == FOX_IMAGE) {
				newOrganism = new Fox(x, y, this);
			}
			else if (organismImage == GRASS_IMAGE) {
				newOrganism = new Grass(x, y, this);
			}
			else if (organismImage == GUARANA_IMAGE) {
				newOrganism = new Guarana(x, y, this);
			}
			else if (organismImage == HUMAN_IMAGE) {
				newOrganism = new Human(x, y, this);
				file >> superpowerActive >> roundCounter;
			}
			else if (organismImage == NIGHTSHADE_IMAGE) {
				newOrganism = new Nightshade(x, y, this);
			}
			else if (organismImage == SHEEP_IMAGE) {
				newOrganism = new Sheep(x, y, this);
			}
			else if (organismImage == SOSNOWSKY_HOGWEED_IMAGE) {
				newOrganism = new SosnowskyHogweed(x, y, this);
			}
			else if (organismImage == TURTLE_IMAGE) {
				newOrganism = new Turtle(x, y, this);
			}
			else if (organismImage == WOLF_IMAGE) {
				newOrganism = new Wolf(x, y, this);
			}
			newOrganism->setStrength(strength);
			newOrganism->setInitiative(initiative);
			newOrganism->setAliveState(alive);
			newOrganism->setAge(age);
			if (newOrganism->getImage() == HUMAN_IMAGE) {
				Human* humanPointer = dynamic_cast<Human*>(newOrganism);
				humanPointer->setSuperpowerState(superpowerActive);
				humanPointer->setRoundCounter(roundCounter);
			}
			allOrganisms.push_back(newOrganism);
		}
		file.close();
	}
	else {
		cout << "Plik nie istnieje!";
		char input = EMPTY;
		while (true) {
			input = _getch();
			if (input == NEW_LINE) {
				break;
			}
		}
	}
}
World::~World() {

}