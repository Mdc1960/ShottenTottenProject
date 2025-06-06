#ifndef FACTORY_AI_PLAYER_H
#define FACTORY_AI_PLAYER_H


#include "FactoryPlayer.h"
#include "AIPlayer.h"

class FactoryAIPlayer : public FactoryPlayer
{

public:

	std::unique_ptr<PlayerInterface> createPlayer(const std::string& name, unsigned int id) override;
};

#endif