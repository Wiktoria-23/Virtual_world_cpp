#include "Plant.h"
#include "Organism.h"

Plant::Plant(int xPosition, int yPosition, World* newWorld) : Organism(xPosition, yPosition, newWorld) {
	initiative = 0;
}
void Plant::action() {
	grow();
}
void Plant::collision() {

}
bool Plant::checkPossibilityToGrow() const {
	if (!currentWorld->checkFieldXY(x - 1, y) || !currentWorld->checkFieldXY(x + 1, y) || !currentWorld->checkFieldXY(x, y - 1) || !currentWorld->checkFieldXY(x, y + 1)) {
		return true;
	}
	return false;
}
void Plant::grow() const {
	if (checkPossibilityToGrow()) {
		int chanceToGrow = rand() % 5;
		if (chanceToGrow == 0) {
			while (true) {
				direction growDirection = (direction)(rand() % 4);
				if (growDirection == UP) {
					if (!currentWorld->checkFieldXY(x, y - 1)) {
						Organism* newPlant = createChild(x, y - 1);
						currentWorld->addOrganism(newPlant);
						break;
					}
				}
				else if (growDirection == DOWN) {
					if (!currentWorld->checkFieldXY(x, y + 1)) {
						Organism* newPlant = createChild(x, y + 1);
						currentWorld->addOrganism(newPlant);
						break;
					}
				}
				else if (growDirection == RIGHT) {
					if (!currentWorld->checkFieldXY(x + 1, y)) {
						Organism* newPlant = createChild(x + 1, y);
						currentWorld->addOrganism(newPlant);
						break;
					}
				}
				else if (growDirection == LEFT) {
					if (!currentWorld->checkFieldXY(x - 1, y)) {
						Organism* newPlant = createChild(x - 1, y);
						currentWorld->addOrganism(newPlant);
						break;
					}
				}
			}
		}
	}
}
Plant::~Plant() {

}