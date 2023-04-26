#pragma once
#ifndef WORLD_H
#define WORLD_H
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define START_AMOUNT 3
#define EMPTY '_'
#define BOARD_START_Y 5
#define INFO_START_X 5
#define NEW_LINE '\r'

using namespace std;

struct coordinates {
	int x;
	int y;
};

class Organism;
class Human;

class World {
private:
	int roundCounter;
	int boardSizeX;
	int boardSizeY;
	COORD cursorCoordinates;
	vector<string*> allEventsInfo;
	vector<Organism*> allOrganisms;
public:
	World(int xSize, int ySize);
	int countOrganismsAmount() const;
	void printWorld();
	void performRound();
	int getRoundCounter() const;
	void incrementRoundCounter();
	coordinates* getRandomEmptyField() const;
	char getImageXY(int x, int y) const;
	bool checkFieldXY(int x, int y) const;
	int getBoardSizeX() const;
	int getBoardSizeY() const;
	Organism& getOrganismFromXY(int x, int y) const;
	Human* getHuman();
	void addOrganism(Organism* newOrganism);
	void addPlantGrowInfo(const Organism& parent);
	void addAnimalBreedInfo(const Organism& parent);
	void addDeathInfo(const Organism& deadOrganism, const Organism& killingOrganism);
	void sortOrganisms();
	void setCursorPosition(int xPosition, int yPosition);
	void addEventsInfo(string& newInfo);
	bool checkIfAnimal(int xPosition, int yPosition) const;
	void save(string& filename) const;
	void loadFromFile(string& filename);
	~World();
	template <typename T>
	void createOrganism() {
		coordinates newCoordinates = *getRandomEmptyField();
		T* newOrganism = new T(newCoordinates.x, newCoordinates.y, this);
		allOrganisms.insert(allOrganisms.begin(), newOrganism);
	}
};

#endif // !WORLD_H