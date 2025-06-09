#ifndef FACTORY_PLAYER_H
#define FACTORY_PLAYER_H


#include "PlayerInterface.h"


class FactoryPlayer {

public:

	virtual std::unique_ptr<PlayerInterface> createPlayer(const std::string& name, unsigned int id) = 0;

	virtual ~FactoryPlayer() = default;

};


#endif;