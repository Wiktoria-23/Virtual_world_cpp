#include "Plant.h"
#include "Organism.h"

Plant::Plant(int xPosition, int yPosition, World* newWorld) : Organism(xPosition, yPosition, newWorld) {
	initiative = BASE_INITIATIVE;
	strength = BASE_STRENGTH;
}
void Plant::action() {
	grow();
}
void Plant::collision(Organism* collidingOrganism) {

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
			while (true) {
				direction growDirection = (direction)(rand() % 4);
				if (growDirection == UP) {
					if (!currentWorld->checkFieldXY(x, y - 1)) {
						Organism* newPlant = createChild(x, y - 1);
						currentWorld->addOrganism(newPlant);
						/*string* info = new string("Roslina ");
						char* type = new char(image);
						info->append(type);*/
						/*info->append()*///napisa� funkcj� �wiata wy�wietlaj�c� komunikaty
						/*currentWorld->addEventsInfo(*/
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