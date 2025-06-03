#include "Border.h"

Border::Border() :
	status(BorderStatus::BORDER_IS_NOT_REVENDICATED)
{
	fillPlayerSides();
}


void Border::pushCardInBorder(std::unique_ptr<CardInterface> card)
{
}

void Border::popCardInBorder(std::unique_ptr<CardInterface> card)
{
}

unsigned int Border::getMaxCapacityInPlayerSide(unsigned int&& indexPlayerSides) const
{
	unsigned int cap = 3;

	if (this->firstPlayerBorderSide.getCapacity() == this->secondPlayerBorderSide.getCapacity()) {
		cap = this->firstPlayerBorderSide.getCapacity();
	}

	return cap;
}






void Border::printFirstPlayerBorderSide()
{
	std::cout << "Border First Side : \n";  firstPlayerBorderSide.printCardSet();
}

void Border::printSecondPlayerBorderSide()
{
	std::cout << "Border Second Side : \n";  secondPlayerBorderSide.printCardSet();
}


void Border::fillPlayerSides()
{
	PlayerSide* firstSide = new PlayerSide();
	PlayerSide* secondSide = new PlayerSide();

	firstSide->fillCardSet();
	secondSide->fillCardSet();

	firstPlayerBorderSide = *firstSide;
	secondPlayerBorderSide = *secondSide;
}
