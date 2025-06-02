#pragma once
#include "CardElite.h"

#include <iostream>

using namespace std;

class Espion : public CardElite
{
public:
	string getNamecard() override { return "Espion"; }
	void applyEffet() override;
};