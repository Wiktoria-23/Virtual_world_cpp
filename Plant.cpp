#include "Plant.h"
#include "Organism.h"

Plant::Plant(int xPosition, int yPosition, World* newWorld) : Organism(xPosition, yPosition, newWorld) {
	initiative = 0;
}
void Plant::action() {
	//growth
}
void Plant::collision() {

}
void Plant::grow() const {
	int chanceToGrow = rand() % 5;
	if (chanceToGrow == 0) { //add checking plant type
		while (true) {
			direction growDirection = (direction)(rand() % 4);
			if (growDirection == UP) {
				if (!currentWorld->checkFieldXY(x, y - 1)) {
					/*currentWorld->createOrganism<*/
					break;
				}
			}
			else if (growDirection == DOWN) {
				if (!currentWorld->checkFieldXY(x, y + 1)) {
					//grow
					break;
				}
			}
			else if (growDirection == RIGHT) {
				if (!currentWorld->checkFieldXY(x + 1, y)) {
					//grow
					break;
				}
			}
			else if (growDirection == LEFT) {
				if (!currentWorld->checkFieldXY(x - 1, y)) {
					//grow
					break;
				}
			}
		}
	}
}
Plant::~Plant() {

}