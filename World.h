#pragma once
#ifndef WORLD_H
#define WORLD_H
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
#define START_AMOUNT 3
#define EMPTY '_'

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
	int randOrganismsAmount();
	void printWorld();
	void performRound();
	int getRoundCounter() const;
	void incrementRoundCounter();
	coordinates* getRandomEmptyField() const;
	char getImageXY(int x, int y) const;
	bool checkFieldXY(int x, int y) const;
	int getBoardSizeX() const;
	int getBoardSizeY() const;
	Organism& getOrganismFromXY(int x, int y);
	Human* getHuman();
	void addOrganism(Organism* newOrganism);
	void killOrganismFromXY(int xPosition, int yPosition);
	void sortOrganisms();
	void setCursorPosition(int xPosition, int yPosition);
	void addEventsInfo(string* newInfo);
	bool checkIfAnimal(int xPosition, int yPosition);
	~World();
	template <typename T>
	void createOrganisms() {
		for (int i = 0; i < randOrganismsAmount(); i++) {
			coordinates newCoordinates = *getRandomEmptyField();
			createOrganism<T>(newCoordinates.x, newCoordinates.y);
		}
	}
	template <typename T>
	void createOrganism(int x, int y) {
		T* newOrganism = new T(x, y, this);
		allOrganisms.insert(allOrganisms.begin(), newOrganism);
	}
};

#endif // !WORLD_H