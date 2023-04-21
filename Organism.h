#ifndef ORGANISM_H
#define ORGANISM_H
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "World.h"

enum direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NONE,
};

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
	virtual void action() = 0;
	virtual void collision(Organism* collidingOrganism) const = 0;
	void baseFight(Organism* collidingOrganism) const;
	void incrementAgeCounter();
	Organism* getCollision(direction moveDirection);
	/*string& createDeathInfo();*/
	virtual Organism* createChild(int xPosition, int yPosition) const = 0;
	virtual ~Organism();
};

#endif // !ORGANISM_H