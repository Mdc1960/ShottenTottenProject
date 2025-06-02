#pragma once
#include "CardElite.h"

#include <iostream>

using namespace std;

class PorteBouclier : public CardElite
{
	string getNamecard() override { return "Porte-Bouclier"; }
	void applyEffet() override;
};

