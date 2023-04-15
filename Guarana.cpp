#include "Guarana.h"

Guarana::Guarana(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = 0;
	image = 'G';
}
Organism* Guarana::createChild(int xPosition, int yPosition) const {
	Organism* newGuarana = new Guarana(xPosition, yPosition, currentWorld);
	return newGuarana;
}
void Guarana::collision() {
	//makes animal stronger
}
Guarana::~Guarana() {

}