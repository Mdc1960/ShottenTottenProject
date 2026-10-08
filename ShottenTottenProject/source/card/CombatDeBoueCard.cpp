#include "CombatDeBoueCard.h"

#include <iostream>

void CombatDeBoueCard::printCard()
{
	std::cout << this->getNamecard() << std::endl;
}

void CombatDeBoueCard::applyEffet(unique_ptr<Border>& border)
{
	border = make_unique<CBDecorator>(move(border));

}

string CombatDeBoueCard::getNamecard()
{
	return "Conbat de Boue";
}
