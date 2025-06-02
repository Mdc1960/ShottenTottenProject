#pragma once
#include "CardElite.h"

class Espion : public CardElite
{
public:
	string getNamecard() override { return "Espion"; }
	void applyEffet() override;
};

