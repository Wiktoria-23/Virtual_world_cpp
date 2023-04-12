#pragma once
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
	template <typename T>
	void createOrganisms() {
		for (int i = 0; i < START_AMOUNT; i++) {
			coordinates newCoordinates = *getEmptyField();
			T* newOrganism = new T(newCoordinates.x, newCoordinates.y);
			allOrganisms.push_back(newOrganism);
		}
	}
	void printWorld();
	void performRound();
	int getRoundCounter();
	void incrementRoundCounter();
	coordinates* getEmptyField();
	char getImageXY(int x, int y);
	bool checkFieldXY(int x, int y);
	void sortOrganisms();
	~World();
};