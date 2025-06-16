#pragma once
#include "CardElite.h"

#include <iostream>

using namespace std;

class Joker : public CardElite
{
public:
	void printCard() override;
	string getNamecard() override { return "Joker"; }
	void applyEffet() override;
};