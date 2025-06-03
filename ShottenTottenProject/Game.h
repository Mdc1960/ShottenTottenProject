#ifndef GAME_SHOTTEN_TOTTEN_H
#define GAME_SHOTTEN_TOTTEN_H

#include "PlayerInterface.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "Bord.h"
#include "Phase.h"
#include "PlayerPlay.h"
#include "RevendicateBorder.h"


class Game
{

private :

	bool isGameOver = false;
	bool isConfiguring = false;

	Bord& gameBord = Bord::getInstance();
	std::unique_ptr<PlayerInterface> firstPlayer;
	std::unique_ptr<PlayerInterface> secondPlayer;
	std::unique_ptr<Phase> playPhase;
	std::unique_ptr<Phase> revendicatePhase;

	void buildGameBord(unsigned int&& clanStackSize, unsigned int&& tacticStackSize);
	void printFirstPlayerBorderSide();
	void printSecondPlayerBorderSide();
	void printBorderSeparator();

	void startConfiguration();


	void shuffledGameClanStack();
	void shuffledGameTacticStack();

public :

	Game();

};

#endif