#pragma once
#include "CardTactic.h"

class Ruse : public CardTactic
{
public :
	void applyEffet(unique_ptr<Border>& border) = 0;
	string getNamecard() = 0;
};

