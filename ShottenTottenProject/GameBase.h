#ifndef GAME_BASE_H
#define GAME_BASE_H

#include "Game.h"


class GameBase : public Game
{

public :

	GameBase();

	void startGame() override;

};

#endif