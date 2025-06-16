#pragma once
#include "CardElite.h"

#include <iostream>

using namespace std;

class PorteBouclier : public CardElite
{
public:
	void printCard() override;
	string getNamecard() override { return "Porte-Bouclier"; }
	void applyEffet(unique_ptr<Border>& border) override;
};

