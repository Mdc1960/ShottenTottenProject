#include "Bord.h"

Bord* Bord::instance = nullptr;

Bord::Bord()
{
	clanStack = nullptr;
	tacticStack = nullptr;
	borders = nullptr;
	defausse = nullptr;
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

void Bord::shuffledClanStack()
{
	clanStack->shuffledStack();
}

void Bord::shuffledTacticStack()
{
	tacticStack->shuffledStack();
}

void Bord::printFirstPlayerBorderSide()
{
	borders->printFirstPlayerBorderSide();
}

void Bord::printSecondPlayerBorderSide()
{
	borders->printSecondPlayerBorderSide();
}

void Bord::fillBord(unsigned int&& clanCapacity, unsigned int&& tacticCapacity)
{
	borders = std::make_unique<Border>();
	defausse = std::make_unique<Defausse>();
	createClanStack(std::move(clanCapacity));
	createTacticStack(std::move(tacticCapacity));
}
