#include "Antelope.h"

Antelope::Antelope(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	image = 'A';
	speed = 2;
}
void Antelope::action() {

}
void Antelope::collision() {

}
Antelope::~Antelope() {

}