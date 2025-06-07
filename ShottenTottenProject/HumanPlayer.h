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
};

#endif