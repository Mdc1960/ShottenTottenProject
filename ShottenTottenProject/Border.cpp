#include "Border.h"

Border::Border() :
	status(BorderStatus::BORDER_IS_NOT_REVENDICATED), listIndexBorderClaimed()
	
{
	fillPlayerSides();
}


std::vector<std::string> Border::getAllCardColorInPlayerSide(unsigned int&& playerSideId)
{
	switch (playerSideId) {
	case 1:
		return firstPlayerBorderSide->getAllCardColor();
		break;
	case 2:
		return secondPlayerBorderSide->getAllCardColor();
		break;
	default:
		break;
	}
	return std::vector<std::string>();
}

void Border::pushCardInBorder(std::unique_ptr<CardInterface> card)
{
}

void Border::popCardInBorder(std::unique_ptr<CardInterface> card)
{
}

unsigned int Border::getMaxCapacityInPlayerSide() const
{
	unsigned int cap = 3;

	if (this->firstPlayerBorderSide->getCapacity() == this->secondPlayerBorderSide->getCapacity()) {
		cap = this->firstPlayerBorderSide->getCapacity();
	}

	return cap;
}

void Border::setFirstPlayerSide(std::unique_ptr<PlayerSide> playerSide)
{
	this->firstPlayerBorderSide = std::move(playerSide);
}

void Border::setSecondPlayerSide(std::unique_ptr<PlayerSide> playerSide)
{
	this->secondPlayerBorderSide = std::move(playerSide);
}

void Border::printBorder()
{
	printFirstPlayerBorderSide();
	std::cout << "====";
	printSecondPlayerBorderSide();
}

void Border::printFirtPlayerSideCardByIndex(unsigned int&& index)
{
	firstPlayerBorderSide->printCardByIndex(std::move(index));
}

void Border::printSecondPlayerSideCardByIndex(unsigned int&& index)
{
	secondPlayerBorderSide->printCardByIndex(std::move(index));
}

void Border::putCardInFirstPlayerSide(std::unique_ptr<CardInterface> card)
{
	try {
		firstPlayerBorderSide->putCardInCardSet(std::move(card));
	}
	catch (GameException exp) {
		throw;
	}
	
}

void Border::putCardInSecondPlayerSide(std::unique_ptr<CardInterface> card)
{
	try {
		secondPlayerBorderSide->putCardInCardSet(std::move(card));
	}
	catch (GameException exp) {
		throw;
	}
	
}






void Border::printFirstPlayerBorderSide()
{
	std::cout << "Border First Side : \n";  firstPlayerBorderSide->printCardSet();
}

void Border::printSecondPlayerBorderSide()
{
	std::cout << "Border Second Side : \n";  secondPlayerBorderSide->printCardSetInReverse();
}

CardInterface* Border::getCardInPlayerSide(unsigned int&& playerSideId, unsigned int&& indexCard)
{
	
	switch (std::move(playerSideId)) {
	case 1:
		if (std::move(indexCard) < firstPlayerBorderSide->size()) {
			return firstPlayerBorderSide->getCardByIndex(std::move(indexCard));
		}
		break;
	case 2:
		if (std::move(indexCard) < secondPlayerBorderSide->size()) {
			return secondPlayerBorderSide->getCardByIndex(std::move(indexCard));
		}
		break;
	default:
		break;
	}
	return nullptr;
}


void Border::fillPlayerSides()
{
	firstPlayerBorderSide = std::make_unique<PlayerSide>();
	secondPlayerBorderSide = std::make_unique<PlayerSide>();

	firstPlayerBorderSide->fillCardSet();
	secondPlayerBorderSide->fillCardSet();

}
