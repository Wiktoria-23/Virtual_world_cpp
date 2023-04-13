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

class World {
private:
	int roundCounter;
	int boardX;
	int boardY;
	vector<Organism*> allOrganisms;
public:
	World(int xSize, int ySize);
	int randOrganismsAmount();
	template <typename T>
	void createOrganisms() {
		for (int i = 0; i < randOrganismsAmount(); i++) {
			coordinates newCoordinates = *getRandomEmptyField();//poprawiæ konstruktory klas
			T* newOrganism = new T(newCoordinates.x, newCoordinates.y, this);
			allOrganisms.push_back(newOrganism);
		}
	}
	void printWorld();
	void performRound();
	int getRoundCounter();
	void incrementRoundCounter();
	coordinates* getRandomEmptyField();
	char getImageXY(int x, int y);
	bool checkFieldXY(int x, int y);
	void sortOrganisms();
	~World();
};

#endif // !WORLD_H