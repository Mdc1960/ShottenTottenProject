#include "CombatDeBoueCard.h"

#include <iostream>

void CombatDeBoueCard::printCard()
{
	std::cout << this->getNamecard() << std::endl;
}

void CombatDeBoueCard::applyEffet()
{
}

string CombatDeBoueCard::getNamecard()
{
	return "Conbat de Boue";
}
