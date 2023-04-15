#pragma once
#include "Organism.h"

class Grass;
class Dandelion;
class Guarana;
class Nightshade;
class SosnowskyHogweed;

class Plant : public Organism {
public:
	Plant(int xPosition, int yPosition, World* newWorld);
	virtual void action() override;
	virtual void collision() override;
	virtual Organism* createChild(int xPosition, int yPosition) const = 0;
	bool checkPossibilityToGrow() const;
	virtual void grow() const;
	~Plant();
};