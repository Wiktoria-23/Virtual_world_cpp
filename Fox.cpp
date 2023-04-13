#include "Fox.h"
#include "World.h"

Fox::Fox(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = 3;
	initiative = 7;
	image = 'L';
}
void Fox::action() {
	//direction moveDirection;
	//while (true) {
	//	moveDirection = (direction)(rand() % 4);
	//	if (moveDirection == LEFT) {
	//		if (!currentWorld->checkFieldXY(x - speed, y)) {
	//			break;
	//		}
	//		/*else {
	//			if (currentWorld.)
	//		}*/
	//	}
	//}
	//baseMovement(moveDirection);
}
Fox::~Fox() {

}