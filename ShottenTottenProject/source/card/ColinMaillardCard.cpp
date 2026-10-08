#include "ColinMaillardCard.h"
#include <iostream>

void ColinMaillardCard::printCard()
{
	std::cout << this->getNamecard() << std::endl;
}

void ColinMaillardCard::applyEffet(unique_ptr<Border>& border)
{
	border = make_unique<CollinMaillard>(move(border));
}

string ColinMaillardCard::getNamecard()
{
	return "ColinMaillard-Card";
}
