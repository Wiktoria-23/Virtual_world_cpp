#include "Organism.h"
#include "World.h"

int Organism::getStrength() const {
	return strength;
}
int Organism::getInitiative() const {
	return initiative;
}
int Organism::getX() const {
	return x;
}
int Organism::getY() const {
	return y;
}
char Organism::getImage() const {
	return image;
}
int Organism::getAge() const {
	return age;
}
void Organism::print() const {

}
Organism::~Organism() {

}