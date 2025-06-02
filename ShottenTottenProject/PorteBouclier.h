#pragma once
#include "CardElite.h"

class PorteBouclier : public CardElite
{
	string getNamecard() override { return "Porte-Bouclier"; }
	void applyEffet() override;
};

