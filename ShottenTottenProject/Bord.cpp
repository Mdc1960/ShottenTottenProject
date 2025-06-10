#include "Bord.h"
#include "Game.h"

/*!
* Bord
*/
Bord* Bord::instance = nullptr;

unsigned int Bord::numberOfCardPutInBorders = 0;

Bord::Bord()
{
	//fillBord(std::move(56),std::move(12));
	defausse = std::make_unique<Defausse>();
	borders = std::vector<std::unique_ptr<Border>>();
	fillBorders();
}
Bord::~Bord()
{
}

Bord& Bord::getInstance()
{
	if (instance == nullptr) {
		instance = new Bord();
	}
	return *instance;
}

void Bord::update(Observable* observable)
{
	if (dynamic_cast<Game*>(observable)) {
		((Game*)observable)->displayGameBord();
	}
}

void Bord::createClanStack(unsigned int&& capacity)
{
	clanStack = std::make_unique<Stack>(std::move(capacity));
	clanStack->fillClanStack();
}

void Bord::createTacticStack(unsigned int&& capacity)
{
	tacticStack = std::make_unique<Stack>(std::move(capacity));
	tacticStack->fillTacticStack();
}

void Bord::fillBorders()
{
	for (unsigned int index = 0; index < MAX_BORDER_NUMBER_IN_BORD; index++) {
		borders.push_back(std::move(std::make_unique<BorderBase>()));
	}
}

void Bord::shuffledClanStack()
{
	clanStack->shuffledStack();
}

void Bord::shuffledTacticStack()
{
	tacticStack->shuffledStack();
}

const unsigned int Bord::getBorderSidePutCardIndex(unsigned int&& borderIndex, unsigned int&& sideId)
{
	unsigned int counter = 0;
	for (auto& border : borders) {
		if (counter == borderIndex) {
			if (std::move(sideId) == 1) {
				return border->getFirstPlayerSidePutCardIndex();
			}
			else {
				return border->getSecondPlayerSidePutCardIndex();
			}
		}
		counter++;
	}
	return 0;
}



void Bord::printBorders()
{
	std::cout << std::endl;
	printFirstPlayerBorderSide();
	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "============================================================================================================\n";
	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	printSecondPlayerBorderSide();
	std::cout << std::endl;
}

size_t Bord::getBorderSize() const
{
	return borders.size();
}

void Bord::printFirstPlayerBorderSide()
{
	for (unsigned int index = 3; index > 0; --index) {
		for (auto& border : borders) {
			border->printFirtPlayerSideCardByIndex(index - 1);
		}
		std::cout << std::endl;
	}
	
}

void Bord::printSecondPlayerBorderSide()
{
	for (unsigned int index = 0; index < 3; index++) {
		for (auto& border : borders) {
			border->printSecondPlayerSideCardByIndex(std::move(index + 0));
		}
		std::cout << std::endl;
	}
	
}

void Bord::createBordStacks(unsigned int&& clanCapacity, unsigned int&& tacticCapacity)
{
	createClanStack(std::move(clanCapacity));
	createTacticStack(std::move(tacticCapacity));
}

void Bord::putCardInBorderByPlayerIdAndColumnIndex(std::unique_ptr<CardInterface> card, unsigned int&& playerId, unsigned int&& columnIndex)
{
	if (columnIndex < 9) {
		switch (playerId) {
		case 1:
			borders[columnIndex]->putCardInFirstPlayerSide(std::move(card));
			numberOfCardPutInBorders++;
			break;
		case 2:
			borders[columnIndex]->putCardInSecondPlayerSide(std::move(card));
			numberOfCardPutInBorders++;
			break;
		default:
			break;
		}
	}
}

void Bord::showClanStack()
{
	clanStack->printCardSet();
}

void Bord::showTacticStack()
{
	tacticStack->printCardSet();
}

std::unique_ptr<CardInterface> Bord::popAndGetCardFromClanStack()
{
	return clanStack->popAndGetBackCard();
}

std::unique_ptr<CardInterface> Bord::popAndGetCardFromTacticStack()
{
	return tacticStack->popAndGetBackCard();
}

void Bord::setIsClanStackEmpty(bool&& b)
{
	this->isClanStackEmpty = b;
}

const bool Bord::getIsClanStackEmpty() const
{
	return isClanStackEmpty;
}

std::unordered_map<std::string, unsigned int> Bord::fillPlayerRevendicateMap(unsigned int& revendicateColumn, unsigned int&& playerSideId)
{
	unsigned int counter = 0;
	for (auto& border : borders) {
		if (counter == revendicateColumn) {
			return border->fillPlayerRevendicateMap(std::move(playerSideId));
		}
		else {
			counter++;
		}
	}
	return std::unordered_map<std::string, unsigned int>();
}
