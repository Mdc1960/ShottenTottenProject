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

/** 
 * @brief A class representing the game.
 * This class inherits from Observable and provides an interface for managing the game state, players, and game phases.
 */
class Game : public Observable
{

protected:

	/** 
	 * @brief Adds an observer to the game.
	 * @param observer The observer to add.
	 */
	void add(Observer* observer) override;

	/** 
	 * @brief Removes an observer from the game.
	 * @param observer The observer to remove.
	 */
	void remove(Observer* observer) override;

	/** 
	 * @brief Notifies all observers of a change in the game state.
	 */
	void notify() override;

	
	/** 
	 * @brief A reference to the singleton instance of the Bord class representing the game board.
	 */
	Bord& gameBord = Bord::getInstance();

	/** 
	 * @brief A unique pointer to the first player in the game.
	 */
	std::unique_ptr<PlayerInterface> firstPlayer = nullptr;

	/** 
	 * @brief A unique pointer to the second player in the game.
	 */
	std::unique_ptr<PlayerInterface> secondPlayer = nullptr;

	/** 
	 * @brief A shared pointer to the current play phase.
	 */
	std::shared_ptr<Phase> playPhase;

	/** 
	 * @brief A shared pointer to the current revendicate phase.
	 */
	std::shared_ptr<Phase> revendicatePhase;

	/** 
	 * @brief The mode of the game.
	 */
	GameMode gameMode;

	/** 
	 * @brief A vector of observers for the game.
	 */
	std::vector<Observer*> listObserver;

	/** 
	 * @brief A vector of border indices for the first player's revendicate actions.
	 */
	std::vector<unsigned int> firstPlayerRevendicateBorderList = std::vector<unsigned int>();

	/** 
	 * @brief A vector of border indices for the AI player's revendicate actions.
	 */
	std::vector<unsigned int> aiPlayerRevendicateBorderList = std::vector<unsigned int>();

	/** 
	 * @brief A vector of border indices for the opponent player's revendicate actions.
	 */
	std::vector<unsigned int> opponentPlayerRevendicateBorderList = std::vector<unsigned int>();

	/**
	 * @brief A player combination.
	 */
	unsigned int playerCombination = 0;

	/**
	 * @brief The opponent Combination.
	 */
	unsigned int opponentCombination = 0;

	/**
	 * @brief AI combination.
	 */
	unsigned int aiCombination = 0;

	/**
	 * @brief A turn of a specific player.
	 */
	unsigned int turn;

	/**
	 * @brief Opponent card choise.
	 */
	unsigned int opponentChoiseMade = 0;

	/**
	 * @brief Check if the game is over.
	 */
	bool isGameOver = false;

	/**
	 * @brief Check if the game configure.
	 */
	bool isConfiguring = false;

	/**
	 * @brief Method used to build the game board.
	 * @param clanStackSize : A size of clan card stack.
	 * @param tacticStackSize : A size of tactic card stack.
	 */
	void buildGameBord(unsigned int&& clanStackSize, unsigned int&& tacticStackSize);

	//void startConfiguration();
	
	/**
	 * @brief Shuffle the clan card.
	 */
	void shuffledGameClanStack();

	/**
	 * @brief Shuffle the tactic card.
	 */
	void shuffledGameTacticStack();

	/**
	 * @brief Get card from tactic stack.
	 */
	std::unique_ptr<CardInterface> getCardFromCardTackticStack();
	
	/**
	 * @brief Print the game mode.
	 */
	void printMode();
	
	/**
	 * @brief Show a player hand.
	 * @param id : A player id.
	 */
	void showHumanPlayerHand(unsigned int&& id);

	/**
	 * @brief Set human player combination.
	 * @param combination : The total combination.
	 */
	void setPlayerCombination(unsigned int&& combination);

	/**
	 * @brief Set human player combination.
	 * @param combination : The total combination.
	 */
	void setOpponentCombination(unsigned int&& combination);

	/**
	 * @brief Set AI player combination.
	 * @param combination : The total combination.
	 */
	void setAICombination(unsigned int&& combination);

	/**
	 * @brief Fill a player hand with card using player id.
	 * @param id : A player id.
	 */
	void fillPlayerHandWithInitialCardsUsingId(unsigned int&& id);

	/**
	 * @brief Set the play phase.
	 * @param playPhase : The game phase.
	 */
	void setPlayPhase(std::shared_ptr<Phase> playPhase);

	/**
	 * @brief Set revendicate phase.
	 * @param revendicatePhase : The game revendicate phase.
	 */
	void setRevendicatePhase(std::shared_ptr<Phase> revendicatePhase);

	/**
	 * @brief Set the opponent choise made.
	 * @param opponentChoiseMade : The choise of the opponent.
	 */
	void setOpponentChoiseMade(const unsigned int& opponentChoiseMade);

	/**
	 * @brief Set player played card.
	 * @param borderIndex : The border index.
	 * @param lastPlayerSidePutCard : The index of last played card.
	 */
	void setLastPlayerSidePutCard(unsigned int borderIndex,unsigned int lastPlayerSidePutCard);

	/**
	 * @brief Get the index of the last played card.
	 * @param borderIndex : The index in a border.
	 * @return The index of played card.
	 */
	const unsigned int getLastPlayerSidePutCard(unsigned int borderIndex);

	/**
	 * @brief Add a new revendicate border to player revendicate list.
	 * @param playerId : The id of a player.
	 * @param revendicateColumn : The column a player want to revendicate.
	 */
	void putRevendicatedBorderIndexInPlayerListById(unsigned int&& playerId, unsigned int& revendicateColumn);

	/**
	 * @brief Fill a player revendicate map.
	 * @param revendicateColumn : The column a player want to revendicate.
	 * @param playerSideId : The player side id.
	 * @return A new map with the updated values.
	 */
	std::unordered_map<std::string,unsigned int> fillPlayerRevendicateMap(unsigned int& revendicateColumn, unsigned int&& playerSideId);

	/**
	 * @brief Calculate the total of all revendicate boarder.
	 * @param map : A player revendicate map.
	 * @return The total of all revendicate boarder.
	 */
	const unsigned int getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map);

	/**
	 * @brief Find the winner of a specific boarder.
	 * @param firstCombination : The first player combination.
	 * @param secondCombination : The second player combination.
	 * @return The winner of a specific boarder.
	 */
	const unsigned int determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination);

	/**
	 * @brief Check if a player win the game.
	 * @param listRevendicateBorder : A list of all revendicate boarder of a player.
	 * @return True if the player win the boarder, otherwise False is returned.
	 */
	bool isPlayerWinTheGame(std::vector<unsigned int> listRevendicateBorder);

	/**
	 * @brief Method used to find a specific value in a list.
	 * @param list : A list contening some values.
	 * @param value : A value we wanted to determine if it is an element of a list.
	 * @return True if the value belong to the list, otherwise it return False.
	 */
	bool findValueInList(std::vector<unsigned int> list, unsigned int value);

	/**
	 * @brief Determine the winner of a partie.
	 * @return The id of a player who won the game.
	 */
	unsigned int determineWinnerOfTheGameAtTheEnd();

	/**
	 * @brief Method used to configure the game.
	 */
	void configuredPlayers();

public :

	/**
	 * @brief A default constructor.
	 */
	Game();

	/**
	 * @brief Method used to start the game.
	 */
	virtual void startGame() = 0;

	/**
	 * @brief Method used to put a caard in a boarder.
	 * @param card : The card to play.
	 * @param playerId : A player id.
	 * @param columnIndex : The column a player want to play.
	 */
	void putCardInBordersColumnUsingPlayerId(std::unique_ptr<CardInterface> card, unsigned int&& playerId, unsigned int&& columnIndex);
	
	/**
	 * @brief Display the game board and all players.
	 */
	void displayGameBord();

	/**
	 * @brief Display a clan card stack.
	 */
	void showClanStack();

	/**
	 * @brief Display a tactic card stack.
	 */
	void showTacticStack();

	/**
	 * @brief Method used to get a card in a clan stack.
	 * @return A card to add to a player hand.
	 */
	std::unique_ptr<CardInterface> getCardFromCardClanStack();
	

};

#endif