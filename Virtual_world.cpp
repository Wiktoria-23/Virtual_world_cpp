#include "World.h"
#include "Human.h"
#include <conio.h>
#include <iostream>
#define NEW_ROUND '\r'
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75

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
		character = _getch();
		if (character == 0 || character == 224 || character == -32) {//sprawdź dlaczego -32
			character = _getch();
			if (newWorld.getHuman() != nullptr) {
				if (character == KEY_ARROW_UP) {
					newWorld.getHuman()->setMoveDirection(UP);
				}
				else if (character == KEY_ARROW_DOWN) {
					newWorld.getHuman()->setMoveDirection(DOWN);
				}
				else if (character == KEY_ARROW_LEFT) {
					newWorld.getHuman()->setMoveDirection(LEFT);
				}
				else if (character == KEY_ARROW_RIGHT) {
					newWorld.getHuman()->setMoveDirection(RIGHT);
				}
			}
		}
		else if (character == 'x' && newWorld.getHuman() != nullptr && newWorld.getHuman()->canSuperpowerBeActivated()) {
			newWorld.getHuman()->activateSuperpower();
		}
		else if (character == 'z') {
			system("cls");
			cout << "Podaj nazwe pliku, w ktorym chcesz zapisac stan: " << endl;
			string filename;
			cin >> filename;
			newWorld.save(filename);
			newWorld.printWorld();
		}
		else if (character == 'w') {
			system("cls");
			cout << "Podaj nazwe pliku, z ktorego chcesz odczytac stan: " << endl;
			string filename;
			cin >> filename;
			newWorld.loadFromFile(filename);
			newWorld.printWorld();
		}
		else if (character == NEW_ROUND) {
			newWorld.performRound();
			newWorld.incrementRoundCounter();
			newWorld.printWorld();
		}
	}
	return 0;
}