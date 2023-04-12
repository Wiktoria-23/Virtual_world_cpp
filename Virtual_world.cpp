#include "World.h"
#include <iostream>

using namespace std;

int main() {
	int x, y;
	bool active = true;
	cout << "Wprowadz wielkosc planszy (X,Y): ";
	cin >> x >> y;
	World newWorld(x, y);
	char character;
	newWorld.printWorld();
	while (active) {
		cin >> character;
		if (character == 'n') {
			newWorld.printWorld();
			newWorld.performRound();
			newWorld.incrementRoundCounter();
		}
	}
	return 0;
}