#include "Border.h"

Border::Border() :
	status(BorderStatus::BORDER_IS_NOT_REVENDICATED), listIndexBorderClaimed()
	
{
	fillPlayerSides();
}

void Border::setBorderCapacity(unsigned int newCap)
{
	this->borderCapacity = newCap;
	firstPlayerBorderSide->setCapacity(newCap);
	secondPlayerBorderSide->setCapacity(newCap);
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
	firstPlayerBorderSide->putCardInCardSet(std::move(card));
}

void Border::putCardInSecondPlayerSide(std::unique_ptr<CardInterface> card)
{
	secondPlayerBorderSide->putCardInCardSet(std::move(card));
}






void Border::printFirstPlayerBorderSide()
{
	std::cout << "Border First Side : \n";  firstPlayerBorderSide->printCardSet();
}

void Border::printSecondPlayerBorderSide()
{
	std::cout << "Border Second Side : \n";  secondPlayerBorderSide->printCardSetInReverse();
}

const unsigned int Border::getFirstPlayerSidePutCardIndex() const
{
	return this->firstPlayerBorderSide->getPutCardIndex();
}

const unsigned int Border::getSecondPlayerSidePutCardIndex() const
{
	return this->secondPlayerBorderSide->getPutCardIndex();
}

std::unordered_map<std::string, unsigned int> Border::fillPlayerRevendicateMap(unsigned int&& playerSideId)
{
	std::unordered_map<std::string, unsigned int> map = std::unordered_map<std::string, unsigned int>();
	std::unordered_map<std::string, unsigned int> secondMap = std::unordered_map<std::string, unsigned int>();

	switch (std::move(playerSideId)) {
	case 1:
		map["ColorSequence"] = firstPlayerBorderSide->getPlayerSideCombination(std::move(1));
		map["Set"] = firstPlayerBorderSide->getPlayerSideCombination(std::move(2));
		map["Color"] = firstPlayerBorderSide->getPlayerSideCombination(std::move(3));
		map["Sequence"] = firstPlayerBorderSide->getPlayerSideCombination(std::move(4));
		map["Sum"] = firstPlayerBorderSide->getPlayerSideCombination(std::move(5));
		return map;
	case 2:
		secondMap["ColorSequence"] = secondPlayerBorderSide->getPlayerSideCombination(std::move(1));
		secondMap["Set"] = secondPlayerBorderSide->getPlayerSideCombination(std::move(2));
		secondMap["Color"] = secondPlayerBorderSide->getPlayerSideCombination(std::move(3));
		secondMap["Sequence"] = secondPlayerBorderSide->getPlayerSideCombination(std::move(4));
		secondMap["Sum"] = secondPlayerBorderSide->getPlayerSideCombination(std::move(5));
		return secondMap;
	default:
		break;
	}
	return std::unordered_map<std::string, unsigned int>();
}


CardInterface* Border::getCardInPlayerSide(unsigned int&& playerSideId, unsigned int&& indexCard)
{
	
	switch (std::move(playerSideId)) {
	case 1:
		if (indexCard < firstPlayerBorderSide->size()) {
			return firstPlayerBorderSide->getCardByIndex(std::move(indexCard));
		}
		break;
	case 2:
		if (indexCard < secondPlayerBorderSide->size()) {
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

const unsigned int Border::getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map)
{
	unsigned int totalValue = 0;

	for (auto& m : map) {
		std::cout << "map:::" << m.first << " = " << m.second << std::endl;
		totalValue += m.second;
	}

	return totalValue;
}

std::vector<unsigned int> Border::getFirstPlayerSideAllCardNumber()
{
	return firstPlayerBorderSide->getAllCardNumberInPlayerSide();
}

std::vector<unsigned int> Border::getSecondPlayerSideAllCardNumber()
{
	return secondPlayerBorderSide->getAllCardNumberInPlayerSide();
}

const unsigned int Border::determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination)
{
	unsigned int winner;
	if (firstCombination > secondCombination && firstCombination >= 11) {
		winner = 1;
	}
	else if (secondCombination > firstCombination && secondCombination >= 11) {
		winner = 2;
	}
	else {
		winner = 0;
	}
	return winner;
}
