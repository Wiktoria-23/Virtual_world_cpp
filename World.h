#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

class World {
private:
	int roundCounter;
	int boardX;
	int boardY;
public:
	World(int x, int y);
	void printWorld();
	void performRound();
	int getRoundCounter();
	void incrementRoundCounter();
	~World();
};