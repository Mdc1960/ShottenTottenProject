#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H


#include "PlayerInterface.h"


class HumanPlayer : public PlayerInterface
{

public:

	HumanPlayer(const std::string& name, unsigned int id);

	void chooseBorne() override;
	void claim(Bord& bord) override;
	void chooseCard() override;
	void putCardInGameBordBorder(Bord& bord, std::unique_ptr<CardInterface> card, const unsigned int& chooseBorderIndex) override;
};

#endif