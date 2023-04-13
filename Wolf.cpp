#include "Wolf.h"

Wolf::Wolf(int xPosition, int yPosition, World* newWorld) : Animal(xPosition, yPosition, newWorld) {
	strength = 9;
	initiative = 5;
	image = 'W';
}
Wolf::~Wolf() {

}