#pragma once
#include "CardTactic.h"

class Ruse : public CardTactic
{
public :
	void applyEffet() = 0;
	string getNamecard() = 0;
};

