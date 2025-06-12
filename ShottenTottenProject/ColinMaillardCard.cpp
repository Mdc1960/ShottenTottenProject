#include "ColinMaillardCard.h"
#include <iostream>

void ColinMaillardCard::printCard()
{
	std::cout << this->getNamecard() << std::endl;
}

void ColinMaillardCard::applyEffet()
{
}

string ColinMaillardCard::getNamecard()
{
	return "ColinMaillard-Card";
}
