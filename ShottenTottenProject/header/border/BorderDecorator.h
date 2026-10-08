#ifndef BORDER_DECORATOR_H
#define BORDER_DECORATOR_H

#include "Border.h"

/** 
 * @brief The BorderDecorator class is a decorator for the Border class.
 * It allows for extending the functionality of the Border class without modifying its code.
 */
class BorderDecorator : public Border
{

protected :

	/** 
	 * @brief A unique pointer to the inner Border object being decorated. 
	 */
	std::unique_ptr<Border> innerBorder;

public :

	/** 
	 * @brief Constructs a new BorderDecorator object with the specified inner Border. 
	 * @param param A unique pointer to the inner Border object to be decorated.
	 */
	BorderDecorator(unique_ptr<Border> param) : innerBorder(std::move(param)) {};

	/** 
	 * @brief Sets the capacity of the border. 
	 * @param newCap The new capacity of the border.
	 */
	virtual void setBorderCapacity(unsigned int newCap) override;

	/** 
	 * @brief Gets the capacity of the border. 
	 * @return The capacity of the border.
	 */
	virtual unsigned int getBorderCapacity() override;


	/**
	 * @brief Get all card colors in a player's side.
	 * @param playerSideId The ID of the player's side.
	 * @return A vector of card colors.
	 */
	virtual std::vector<std::string> getAllCardColorInPlayerSide(unsigned int&& playerSideId) override;

	/** 
	 * @brief Pushes a card into the border. 
	 * @param card The card to push.
	 */
	virtual void pushCardInBorder(std::unique_ptr<CardInterface> card) override;

	/** 
	 * @brief Pops a card from the border. 
	 * @param card The card to pop.
	 */
	virtual void popCardInBorder(std::unique_ptr<CardInterface> card)override;

	/** 
	 * @brief Gets the maximum capacity of a player's side. 
	 * @return The maximum capacity of a player's side.
	 */
	virtual unsigned int getMaxCapacityInPlayerSide() const override;

	/** 
	 * @brief Sets the first player's side. 
	 * @param playerSide The first player's side.
	 */
	virtual void setFirstPlayerSide(std::unique_ptr<PlayerSide> playerSide) override;

	/** 
	 * @brief Sets the second player's side. 
	 * @param playerSide The second player's side.
	 */
	virtual void setSecondPlayerSide(std::unique_ptr<PlayerSide> playerSide) override;

	/** 
	 * @brief Prints the border. 
	 */
	virtual void printBorder() override;

	/** 
	 * @brief Prints a card from the first player's side by index. 
	 * @param index The index of the card to print.
	 */
	virtual void printFirtPlayerSideCardByIndex(unsigned int&& index) override;

	/** 
	 * @brief Prints a card from the second player's side by index. 
	 * @param index The index of the card to print.
	 */
	virtual void printSecondPlayerSideCardByIndex(unsigned int&& index) override;

	/** 
	 * @brief Puts a card in the first player's side. 
	 * @param card The card to put.
	 */
	virtual void putCardInFirstPlayerSide(std::unique_ptr<CardInterface> card) override;

	/** 
	 * @brief Puts a card in the second player's side. 
	 * @param card The card to put.
	 */
	virtual void putCardInSecondPlayerSide(std::unique_ptr<CardInterface> card) override;

	/**
	 * @brief Prints the first player's border side. 
	 */
	virtual void printFirstPlayerBorderSide() override;

	/**
	 * @brief Prints the second player's border side. 
	 */
	virtual void printSecondPlayerBorderSide() override;

	/** 
	 * @brief Gets the index of the card put in the first player's side. 
	 * @return The index of the card put in the first player's side.
	 */
	virtual const unsigned int getFirstPlayerSidePutCardIndex() const override;

	/** 
	 * @brief Gets the index of the card put in the second player's side. 
	 * @return The index of the card put in the second player's side.
	 */
	virtual const unsigned int getSecondPlayerSidePutCardIndex() const override;

	/** 
	 * @brief Fills the player's revendicate map. 
	 * @param playerSideId The ID of the player's side.
	 * @return The revendicate map for the specified player's side.
	 */
	virtual std::unordered_map<std::string, unsigned int> fillPlayerRevendicateMap(unsigned int&& playerSideId) override;

	/** 
	 * @brief Gets a card from the specified player's side by index. 
	 * @param playerSideId The ID of the player's side.
	 * @param indexCard The index of the card to get.
	 * @return A pointer to the requested card.
	 */
	virtual CardInterface* getCardInPlayerSide(unsigned int&& playerSideId, unsigned int&& indexCard) override;

	/** 
	 * @brief Determines the border winner by combination. 
	 * @param firstCombination The first combination.
	 * @param secondCombination The second combination.
	 * @return The ID of the winning player.
	 */
	virtual const unsigned int determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination) override;
	
	/** 
	 * @brief Gets the total value of the revendicate border from the map. 
	 * @param map The revendicate map.
	 * @return The total value of the revendicate border.
	 */
	virtual const unsigned int getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map) override;

	/** 
	 * @brief Gets all card numbers in the first player's side. 
	 * @return A vector of card numbers in the first player's side.
	 */
	virtual std::vector<unsigned int> getFirstPlayerSideAllCardNumber() override;

	/** 
	 * @brief Gets all card numbers in the second player's side. 
	 * @return A vector of card numbers in the second player's side.
	 */
	virtual std::vector<unsigned int> getSecondPlayerSideAllCardNumber() override;


	/** 
	 * @brief Claims the border. 
	 * @return The index of the claimed border.
	 */
	unsigned int claim() override;

};

#endif