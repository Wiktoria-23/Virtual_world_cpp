#pragma once
#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <iostream>
#include <vector>
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
	vector<Organism*> allOrganisms;
public:
	World(int xSize, int ySize);
	int randOrganismsAmount();
	void printWorld() const;
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
	void sortOrganisms();
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