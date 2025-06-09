#include "FactoryAIPlayer.h"

std::unique_ptr<PlayerInterface> FactoryAIPlayer::createPlayer(const std::string& name, unsigned int id)
{
    return std::move(std::make_unique<AIPlayer>(name, id));
}
