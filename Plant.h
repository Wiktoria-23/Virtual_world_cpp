#pragma once
#include "Organism.h"
#define BASE_STRENGTH 0
#define BASE_INITIATIVE 0
#define GROW_CHANCE 20

class Grass;
class Dandelion;
class Guarana;
class Nightshade;
class SosnowskyHogweed;

class Plant : public Organism {
public:
	Plant(int xPosition, int yPosition, World* newWorld);
	virtual void action() override;
	virtual void collision(Organism* collidingOrganism) const override;
	virtual Organism* createChild(int xPosition, int yPosition) const = 0;
	bool checkPossibilityToGrow() const;
	virtual void grow() const;
	~Plant();
};