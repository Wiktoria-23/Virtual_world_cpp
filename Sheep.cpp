#include "Sheep.h"

Sheep::Sheep(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = 4;
	initiative = 4;
	image = 'O';
}
Sheep::~Sheep() {

}