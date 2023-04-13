#include "Grass.h"

Grass::Grass(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = 0;
	image = 'T';
}
Grass::~Grass() {

}