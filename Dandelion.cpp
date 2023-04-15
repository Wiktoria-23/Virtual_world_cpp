#include "Dandelion.h"

Dandelion::Dandelion(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = 0;
	image = 'M';
}
void Dandelion::action() {
	//próbuje siê rozprzestrzeniæ trzy razy
}
Dandelion::~Dandelion() {

}