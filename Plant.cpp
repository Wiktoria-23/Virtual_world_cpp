#include "Plant.h"
#include "Organism.h"

Plant::Plant(int xPosition, int yPosition, World* newWorld) : Organism(xPosition, yPosition, newWorld) {
	initiative = BASE_INITIATIVE;
	strength = BASE_STRENGTH;
}
void Plant::action() {
	grow();
}
bool Plant::checkPossibilityToGrow() const {
	if (!currentWorld->checkFieldXY(x - 1, y) || !currentWorld->checkFieldXY(x + 1, y) || !currentWorld->checkFieldXY(x, y - 1) || !currentWorld->checkFieldXY(x, y + 1)) {
		return true;
	}
	return false;
}
void Plant::grow() const {
	if (checkPossibilityToGrow()) {
		int chanceToGrow = rand() % GROW_CHANCE;
		if (chanceToGrow == 0) {
			direction growDirection = (direction)(rand() % 4);
			if (growDirection == UP && y - 1 >= 0) {
				Organism* newPlant = createChild(x, y - 1);
				currentWorld->addOrganism(newPlant);
				currentWorld->addPlantGrowInfo(*this);
			}
			else if (growDirection == DOWN && y + 1 < currentWorld->getBoardSizeY()) {
				Organism* newPlant = createChild(x, y + 1);
				currentWorld->addOrganism(newPlant);
				currentWorld->addPlantGrowInfo(*this);
			}
			else if (growDirection == RIGHT && x + 1 < currentWorld->getBoardSizeX()) {
				Organism* newPlant = createChild(x + 1, y);
				currentWorld->addOrganism(newPlant);
				currentWorld->addPlantGrowInfo(*this);
			}
			else if (growDirection == LEFT && x - 1 >= 0) {
				Organism* newPlant = createChild(x - 1, y);
				currentWorld->addOrganism(newPlant);
				currentWorld->addPlantGrowInfo(*this);
			}
		}
	}
}
Plant::~Plant() {

}