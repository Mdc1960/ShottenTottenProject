#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const std::string& name, unsigned int id) : PlayerInterface(name,id)
{
}

void HumanPlayer::chooseBorne()
{
}

void HumanPlayer::claim(Bord& bord)
{
}

void HumanPlayer::chooseCard()
{
	std::string value = "";
	std::cout << "According to your hand, choose a card you whant to play (0 - 5) : " << std::endl;
	std::cin >> value;
	std::cout << "You choose : " << value << std::endl;
}

void HumanPlayer::putCardInGameBordBorder(Bord& bord, std::unique_ptr<CardInterface> card, const unsigned int& chooseBorderIndex)
{
}
