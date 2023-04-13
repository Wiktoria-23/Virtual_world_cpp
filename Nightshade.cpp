#include "Nightshade.h"

Nightshade::Nightshade(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = 99;
	image = 'J';
}
void Nightshade::collision() {
	//kills an animal
}
Nightshade::~Nightshade() {

}