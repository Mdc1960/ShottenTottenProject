#include "CardClan.h"
#include <iostream>

unsigned int CardClan::counter = 0;

void CardClan::printCard()
{
	std::cout << "$ Name : " << name << std::endl;
}
