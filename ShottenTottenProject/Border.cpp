#include "Border.h"

Border::Border() :
	capacity(9), status(BorderStatus::BORDER_IS_NOT_REVENDICATED)
{
	fillPlayerSides();
}

void Border::claim()
{
	//TODO : Ask claim questions
}

unsigned int Border::getMaxCapacityInPlayerSide(unsigned int&& indexPlayerSides) const
{
	unsigned int cap = 3;

	if (indexPlayerSides < this->capacity) {
		if (this->firstPlayerBorderSide[indexPlayerSides]->getCapacity() == this->secondPlayerBorderSide[indexPlayerSides]->getCapacity()) {
			cap = this->firstPlayerBorderSide[indexPlayerSides]->getCapacity();
		}
		
	}

	return cap;
}



void Border::increasePlayerSideBorderCapacity(unsigned int&& indexPlayerSides)
{
	if (indexPlayerSides < this->capacity) {
		this->firstPlayerBorderSide[indexPlayerSides]->increaseCapacity();
		this->secondPlayerBorderSide[indexPlayerSides]->increaseCapacity();
	}
	
}

void Border::printFirstPlayerBorderSide()
{
	for (auto& playerSide : this->firstPlayerBorderSide) {
		std::cout << "Border First Side : \n		";  playerSide->printCardSet();
	}
}

void Border::printSecondPlayerBorderSide()
{
	for (auto& playerSide : this->secondPlayerBorderSide) {
		std::cout << "Border Second Side : \n		";  playerSide->printCardSet();
	}
}


void Border::fillPlayerSides()
{
	for (unsigned int index = 0; index < capacity; index++) {

		std::unique_ptr<PlayerSide> firstSide = std::make_unique<PlayerSide>();
		std::unique_ptr<PlayerSide> secondSide = std::make_unique<PlayerSide>();

		firstSide->fillCardSet();
		secondSide->fillCardSet();

		firstPlayerBorderSide.push_back(std::move(firstSide));
		secondPlayerBorderSide.push_back(std::move(secondSide));

	}
}
