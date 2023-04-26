#pragma once
#include "Animal.h"
#define FOX_IMAGE 'L'
#define FOX_STRENGTH 3
#define FOX_INITIATIVE 7

class Fox : public Animal {
public:
	Fox(int xPosition, int yPosition, World* newWorld);
	Organism* createChild(int xPosition, int yPosition) const override;
	void action() override;
	bool checkIfAnyMovePossible() const;
	bool checkField(direction moveDirection) const;
	~Fox();
};