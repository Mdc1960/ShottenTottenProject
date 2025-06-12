#pragma once
#include "CardElite.h"

#include <iostream>

using namespace std;

class Espion : public CardElite
{
public:
	void printCard() override;
	string getNamecard() override { return "Espion"; }
	void applyEffet() override;
};