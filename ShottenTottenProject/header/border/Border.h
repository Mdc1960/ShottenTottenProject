#ifndef GAME_BORDER_H
#define GAME_BORDER_H

#include <iostream>
#include <utility>
#include <vector>
#include <iostream>
#include <typeinfo>
#include "CardSet.h"
#include "PlayerSide.h"
#include "GameUtil.h"
#include <unordered_map>



/**
 * @brief The Border class represents a border in the Shotten Totten game.
 * It manages the player sides, card stacks, and border status.
 */
class Border
{

protected :

	/** 
	 * @brief A unique pointer to the first player's side of the border. 
	 */
	std::unique_ptr<PlayerSide> firstPlayerBorderSide;

	/** 
	 * @brief A unique pointer to the second player's side of the border. 
	 */
	std::unique_ptr<PlayerSide> secondPlayerBorderSide;

	/** 
	 * @brief A vector of indices of the borders claimed by players. 
	 */
	std::vector<unsigned int> listIndexBorderClaimed;

	/** 
	 * @brief The status of the border. 
	 */
	BorderStatus			 status;

	/** 
	 * @brief The capacity of the border. 
	 */
	unsigned int borderCapacity = 3;

	/** 
	 * @brief The ID of the last player who put a card in the border. 
	 */
	unsigned int lastPlayerPutCard = 0;


public :

	/** 
	 * @brief Constructs a new Border object. 
	 */
	Border();

	/** 
	 * @brief Sets the capacity of the border. 
	 * @param newCap The new capacity of the border.
	 */
	virtual void setBorderCapacity(unsigned int newCap);

	/** 
	 * @brief Gets the capacity of the border. 
	 * @return The capacity of the border.
	 */
	virtual unsigned int getBorderCapacity() { return borderCapacity; }

	/** 
	 * @brief Claims the border. 
	 */
	virtual unsigned int claim() = 0;

	/** 
	 * @brief Sets the ID of the last player who put a card in the border. 
	 */
	virtual void setLastPlayerPutCard(unsigned int lastPlayerPutCard);

	/** 
	 * @brief Gets the ID of the last player who put a card in the border. 
	 * @return The ID of the last player who put a card in the border.
	 */
	virtual const unsigned int getLastPlayerPutCard() const;

	/** 
	 * @brief Gets all card colors in a player's side. 
	 * @param playerSideId The ID of the player's side.
	 * @return A vector of card colors.
	 */
	virtual std::vector<std::string> getAllCardColorInPlayerSide(unsigned int&& playerSideId);

	/** 
	 * @brief Pushes a card into the border. 
	 * @param card The card to push.
	 */
	virtual void pushCardInBorder(std::unique_ptr<CardInterface> card);

	/** 
	 * @brief Pops a card from the border. 
	 * @param card The card to pop.
	 */
	virtual void popCardInBorder(std::unique_ptr<CardInterface> card);

	/** 
	 * @brief Gets the maximum capacity of a player's side. 
	 * @return The maximum capacity of a player's side.
	 */
	virtual unsigned int getMaxCapacityInPlayerSide() const;

	/** 
	 * @brief Sets the first player's side. 
	 * @param playerSide The first player's side.
	 */
	virtual void setFirstPlayerSide(std::unique_ptr<PlayerSide> playerSide);

	/** 
	 * @brief Sets the second player's side. 
	 * @param playerSide The second player's side.
	 */
	virtual void setSecondPlayerSide(std::unique_ptr<PlayerSide> playerSide);

	/** 
	 * @brief Prints the border. 
	 */
	virtual void printBorder();

	/** 
	 * @brief Prints a card from the first player's side by index. 
	 * @param index The index of the card to print.
	 */
	virtual void printFirtPlayerSideCardByIndex(unsigned int&& index);

	/** 
	 * @brief Prints a card from the second player's side by index. 
	 * @param index The index of the card to print.
	 */
	virtual void printSecondPlayerSideCardByIndex(unsigned int&& index);
	
	/** 
	 * @brief Puts a card in the first player's side. 
	 * @param card The card to put.
	 */
	virtual void putCardInFirstPlayerSide(std::unique_ptr<CardInterface> card);

	/** 
	 * @brief Puts a card in the second player's side. 
	 * @param card The card to put.
	 */
	virtual void putCardInSecondPlayerSide(std::unique_ptr<CardInterface> card);

	/** 
	 * @brief Prints the first player's border side. 
	 */
	virtual void printFirstPlayerBorderSide();

	/** 
	 * @brief Prints the second player's border side. 
	 */
	virtual void printSecondPlayerBorderSide();

	/** 
	 * @brief Gets the index of the card put in the first player's side. 
	 * @return The index of the card put in the first player's side.
	 */
	virtual const unsigned int getFirstPlayerSidePutCardIndex() const;

	/** 
	 * @brief Gets the index of the card put in the second player's side. 
	 * @return The index of the card put in the second player's side.
	 */
	virtual const unsigned int getSecondPlayerSidePutCardIndex() const;

	/** 
	 * @brief Fills the player's revendicate map. 
	 * @param playerSideId The ID of the player's side.
	 * @return The revendicate map for the specified player's side.
	 */
	virtual std::unordered_map<std::string, unsigned int> fillPlayerRevendicateMap(unsigned int&& playerSideId);

	/** 
	 * @brief Gets a card from the specified player's side by index. 
	 * @param playerSideId The ID of the player's side.
	 * @param indexCard The index of the card to get.
	 * @return A pointer to the requested card.
	 */
	virtual CardInterface* getCardInPlayerSide(unsigned int&& playerSideId, unsigned int&& indexCard);

	/** 
	 * @brief Determines the winner of the border based on combinations. 
	 * @param firstCombination The first player's combination.
	 * @param secondCombination The second player's combination.
	 * @return The ID of the winning player.
	 */
	virtual const unsigned int determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination);
	
	/** 
	 * @brief Gets the total value of the revendicate border from a map. 
	 * @param map The map containing the revendicate values.
	 * @return The total value of the revendicate border.
	 */
	virtual const unsigned int getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map);

	/** 
	 * @brief Gets all card numbers from the first player's side. 
	 * @return A vector containing all card numbers from the first player's side.
	 */
	virtual std::vector<unsigned int> getFirstPlayerSideAllCardNumber();

	/** 
	 * @brief Gets all card numbers from the second player's side. 
	 * @return A vector containing all card numbers from the second player's side.
	 */
	virtual std::vector<unsigned int> getSecondPlayerSideAllCardNumber();

	/** 
	 * @brief Gets the capacity of the border. 
	 * @return The capacity of the border.
	 */
	const unsigned int getBorderCapacity() const;

private :

	/** 
	 * @brief Fills the player's sides with cards.
	 */
	void fillPlayerSides();

};

#endif