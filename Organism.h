#pragma once

class Organism {
protected:
	int strength;
	int initiative;
	int x;
	int y;
	char image;
	int age;
public: 
	int getStrength() const;
	int getInitiative() const;
	int getX() const;
	int getY() const;
	virtual void action() = 0;
	virtual void collision() = 0;
	void print() const;
	virtual ~Organism();
};