#include "Bord.h"


/*!
* Bord
*/
Bord* Bord::instance = nullptr;

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

void Bord::createClanStack(unsigned int&& capacity)
{
	clanStack = std::make_unique<Stack>(std::move(capacity));
}

void Bord::createTacticStack(unsigned int&& capacity)
{
	tacticStack = std::make_unique<Stack>(std::move(capacity));
}

void Bord::fillBorders()
{
	for (unsigned int index = 0; index < 9; index++) {
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
	//defausse = std::make_unique<Defausse>();
	createClanStack(std::move(clanCapacity));
	createTacticStack(std::move(tacticCapacity));
}

void Bord::putCardInBorderByPlayerIdAndColumnIndex(std::unique_ptr<CardInterface> card, unsigned int&& playerId, unsigned int&& columnIndex)
{
	if (columnIndex < 9) {
		switch (playerId) {
		case 1:
			borders[columnIndex]->putCardInFirstPlayerSide(std::move(card));
			break;
		case 2:
			borders[columnIndex]->putCardInSecondPlayerSide(std::move(card));
			break;
		default:
			break;
		}
	}
}
