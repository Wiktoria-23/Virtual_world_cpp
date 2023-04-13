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
Plant::~Plant() {

}