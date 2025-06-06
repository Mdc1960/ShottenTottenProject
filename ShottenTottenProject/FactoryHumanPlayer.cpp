#include "FactoryHumanPlayer.h"

std::unique_ptr<PlayerInterface> FactoryHumanPlayer::createPlayer(const std::string& name, unsigned int id)
{
    return std::move(std::make_unique<HumanPlayer>(name, id));
}