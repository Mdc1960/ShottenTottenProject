#ifndef FACTORY_HUMAN_PLAYER_H
#define FACTORY_HUMAN_PLAYER_H


#include "FactoryPlayer.h"
#include "HumanPlayer.h"


class FactoryHumanPlayer : public FactoryPlayer
{

public:
	std::unique_ptr<PlayerInterface> createPlayer(const std::string& name, unsigned int id) override;
};

#endif