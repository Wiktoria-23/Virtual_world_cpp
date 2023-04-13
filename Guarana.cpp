#include "Guarana.h"

Guarana::Guarana(int xPosition, int yPosition, World* newWorld) : Plant(xPosition, yPosition, newWorld) {
	strength = 0;
	image = 'G';
}
void Guarana::collision() {
	//makes animal stronger
}
Guarana::~Guarana() {

}