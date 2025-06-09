#ifndef AI_PLAYER_H
#define AI_PLAYER_H


#include "PlayerInterface.h"
#include <iostream>
#include <random>

class AIPlayer : public PlayerInterface
{

public:

	AIPlayer(const std::string& name, unsigned int id);

	void chooseBorne() override;
	void claim(Bord& bord) override;
	void chooseCard() override;

	const unsigned int generateRandomNumber(unsigned int&& maxNumber, unsigned int&& minNumber) const;

};

#endif