#ifndef GAME_SHOTTEN_TOTTEN_H
#define GAME_SHOTTEN_TOTTEN_H

#include "PlayerInterface.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "Bord.h"
#include "Phase.h"
#include "PlayerPlay.h"
#include "RevendicateBorder.h"
#include "GameUtil.h"
#include "Exception.h"


class Game
{

private :

	

	Bord& gameBord = Bord::getInstance();
	std::unique_ptr<PlayerInterface> firstPlayer;
	std::unique_ptr<PlayerInterface> secondPlayer;
	std::unique_ptr<Phase> playPhase;
	std::unique_ptr<Phase> revendicatePhase;
	GameMode gameMode;

	unsigned int playerCombination = 0;
	unsigned int opponentCombination = 0;
	unsigned int aiCombination = 0;

	bool isGameOver = false;
	bool isConfiguring = false;

	void buildGameBord(unsigned int&& clanStackSize, unsigned int&& tacticStackSize);
	void printFirstPlayerBorderSide();
	void printSecondPlayerBorderSide();
	void printBorderSeparator();

	void startConfiguration();


	void shuffledGameClanStack();
	void shuffledGameTacticStack();

	CardInterface* getCardFromCardClanStack();
	CardInterface* getCardFromCardTackticStack();
	void popCardFromClanStack();
	void popCardFromTacticStack();

	void printMode();
	void startGame();
	void showHumanPlayerHand(unsigned int&& id);

	void setPlayerCombination(unsigned int&& combination);
	void setOpponentCombination(unsigned int&& combination);
	void setAICombination(unsigned int&& combination);

public :

	Game();

};

#endif