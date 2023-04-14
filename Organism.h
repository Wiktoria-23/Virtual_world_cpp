#ifndef ORGANISM_H
#define ORGANISM_H

#pragma once
#include "World.h"

class Organism {
protected:
	int strength;
	int initiative;
	int x;
	int y;
	char image;
	int age;
	World* currentWorld;
public:
	Organism(int xPosition, int yPosition, World* newWorld);
	int getStrength() const;
	int getInitiative() const;
	int getX() const;
	int getY() const;
	char getImage() const;
	int getAge() const;
	bool checkCollision() const;
	virtual void action() = 0;
	virtual void collision() = 0;
	virtual ~Organism();
};

#endif // !ORGANISM_H