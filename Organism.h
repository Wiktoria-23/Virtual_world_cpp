#pragma once

class World;

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
	int getStrength() const;
	int getInitiative() const;
	int getX() const;
	int getY() const;
	char getImage() const;
	int getAge() const;
	virtual void action() = 0;
	virtual void collision() = 0;
	void print() const;
	virtual ~Organism();
};