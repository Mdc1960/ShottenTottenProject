#include "AIPlayer.h"

AIPlayer::AIPlayer(const std::string& name, unsigned int id) : PlayerInterface(name, id)
{
}

void AIPlayer::chooseBorne()
{

	unsigned int column;

	unsigned int maxValue = ALLOW_NUBER_PLAY_BORDER;

	column = generateRandomNumber(std::move(maxValue), std::move(0));

	setChooseBorderIndex(column);
	setIsChooseBoredValid(true);

}

void AIPlayer::claim(Bord& bord)
{
	unsigned int revendicateColumn;
	bool isAIWantToRevendicate;

	unsigned int maxValue = ALLOW_NUBER_PLAY_BORDER;

	isAIWantToRevendicate = generateRandomNumber(std::move(2), std::move(0));

	if (isAIWantToRevendicate) {
		setIsPlayerWantToRevendicate(std::move(true));
	}

	revendicateColumn = generateRandomNumber(std::move(maxValue), std::move(0));

	setRevendicateBorderIndex(revendicateColumn);

}

void AIPlayer::chooseCard()
{
	unsigned int card;

	unsigned int maxValue = ALLOW_NUBER_CARD_COLOR;

	card = generateRandomNumber(std::move(maxValue), std::move(0));

	setChooseCardIndex(card);
	setIsChooseColorValid(true);

}

const unsigned int AIPlayer::generateRandomNumber(unsigned int&& maxNumber, unsigned int&& minNumber) const
{
	std::random_device randomDivice;
	std::mt19937       generator(randomDivice());
	std::uniform_int_distribution<unsigned int> distributor(minNumber, maxNumber - 1);

	return distributor(generator);
}

