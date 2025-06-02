#pragma once
#include "CardElite.h"

class Joker : public CardElite
{
public:
	string getNamecard() override { return "Joker"; }
	void applyEffet() override;
};

