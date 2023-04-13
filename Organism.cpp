#include "Organism.h"
#include "World.h"

Organism::Organism(int xPosition, int yPosition, World* newWorld) : x(xPosition), y(yPosition), currentWorld(newWorld) {
}
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