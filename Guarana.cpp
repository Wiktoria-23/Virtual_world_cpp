#include "Guarana.h"

Guarana::Guarana(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	image = GUARANA_IMAGE;
}
Organism* Guarana::createChild(int xPosition, int yPosition) const {
	Organism* newGuarana = new Guarana(xPosition, yPosition, currentWorld);
	return newGuarana;
}
void Guarana::collision(Organism* collidingOrganism) {
	if (currentWorld->checkIfAnimal(collidingOrganism->getX(), collidingOrganism->getY())) {
		collidingOrganism->increaseStrength(STRENGTH_INCREASE);
	}
	Organism::collision(collidingOrganism);
}
Guarana::~Guarana() {

}