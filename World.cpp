#include "World.h"

World::World(int x, int y) : roundCounter(NULL), boardX(x), boardY(y) {
	//add creating organisms
}
void World::performRound() {

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
			cout << "|_";
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
World::~World() {

}