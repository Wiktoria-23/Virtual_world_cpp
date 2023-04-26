#ifndef HUMAN_H
#define HUMAN_H

#pragma once
#include "Animal.h"
#define HUMAN_IMAGE 'C'
#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4

class Human : public Animal {
private:
	bool superpowerActive;
	int roundCounter;
public:
	Human(int xPosition, int yPosition, World* newWorld);
	void action() override;
	void collision(Organism* collidingOrganism) override;
	void activateSuperpower();
	bool canSuperpowerBeActivated() const;
	bool superpowerState() const;
	int getRoundCounter() const;
	void setDeadState() override;
	void setRoundCounter(int newRoundCounter);
	void setSuperpowerState(bool newSuperpowerState);
	Organism* createChild(int xPosition, int yPosition) const override;
	~Human();
};

#endif // !HUMAN_H