#include "AIPlayer.h"

AIPlayer::AIPlayer(const std::string& name, unsigned int id) : PlayerInterface(name, id)
{
}

void AIPlayer::chooseBorne()
{
}

void AIPlayer::claim(Bord& bord)
{
}

void AIPlayer::chooseCard()
{
}

void AIPlayer::putCardInGameBordBorder(Bord& bord, std::unique_ptr<CardInterface> card, const unsigned int& chooseBorderIndex)
{
}
