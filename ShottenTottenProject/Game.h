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
#include "Observable.h"
#include "Observer.h"
#include "FactoryAIPlayer.h"
#include "FactoryHumanPlayer.h"
#include "PlayerPlay.h"
#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <thread>
#include <unordered_map>

class Bord;


class Game : public Observable
{

protected:

	void add(Observer* observer) override;
	void remove(Observer* observer) override;
	void notify() override;

	

	Bord& gameBord = Bord::getInstance();
	std::unique_ptr<PlayerInterface> firstPlayer = nullptr;
	std::unique_ptr<PlayerInterface> secondPlayer = nullptr;
	std::shared_ptr<Phase> playPhase;
	std::shared_ptr<Phase> revendicatePhase;
	GameMode gameMode;
	std::vector<Observer*> listObserver;

	std::vector<unsigned int> firstPlayerRevendicateBorderList = std::vector<unsigned int>();
	std::vector<unsigned int> aiPlayerRevendicateBorderList = std::vector<unsigned int>();
	std::vector<unsigned int> opponentPlayerRevendicateBorderList = std::vector<unsigned int>();

	unsigned int playerCombination = 0;
	unsigned int opponentCombination = 0;
	unsigned int aiCombination = 0;
	unsigned int turn;

	unsigned int opponentChoiseMade = 0;

	bool isGameOver = false;
	bool isConfiguring = false;

	void buildGameBord(unsigned int&& clanStackSize, unsigned int&& tacticStackSize);

	//void startConfiguration();
	

	void shuffledGameClanStack();
	void shuffledGameTacticStack();

	
	std::unique_ptr<CardInterface> getCardFromCardTackticStack();
	

	void printMode();
	
	void showHumanPlayerHand(unsigned int&& id);

	void setPlayerCombination(unsigned int&& combination);
	void setOpponentCombination(unsigned int&& combination);
	void setAICombination(unsigned int&& combination);

	void fillPlayerHandWithInitialCardsUsingId(unsigned int&& id);

	void setPlayPhase(std::shared_ptr<Phase> playPhase);
	void setRevendicatePhase(std::shared_ptr<Phase> revendicatePhase);
	void setOpponentChoiseMade(const unsigned int& opponentChoiseMade);


	void putRevendicatedBorderIndexInPlayerListById(unsigned int&& playerId, unsigned int& revendicateColumn);

	std::unordered_map<std::string,unsigned int> fillPlayerRevendicateMap(unsigned int& revendicateColumn, unsigned int&& playerSideId);
	const unsigned int getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map);

	const unsigned int determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination);

	void configuredPlayers();

public :

	Game();
	virtual void startGame() = 0;
	void putCardInBordersColumnUsingPlayerId(std::unique_ptr<CardInterface> card, unsigned int&& playerId, unsigned int&& columnIndex);
	void displayGameBord();
	void showClanStack();
	void showTacticStack();
	std::unique_ptr<CardInterface> getCardFromCardClanStack();
	

};

#endif