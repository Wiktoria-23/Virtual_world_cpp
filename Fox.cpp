#include "Fox.h"

Fox::Fox(int xPosition, int yPosition) {
	strength = 3;
	initiative = 7;
	image = 'L';
	x = xPosition;
	y = yPosition;
}
void Fox::action() {
	//do not move to stronger organism
}
Fox::~Fox() {

}