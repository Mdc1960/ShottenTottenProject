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




class Border
{

protected :

	std::unique_ptr<PlayerSide> firstPlayerBorderSide;
	std::unique_ptr<PlayerSide> secondPlayerBorderSide;
	std::vector<unsigned int> listIndexBorderClaimed;
	BorderStatus			 status;

	unsigned int borderCapacity = 3;
	unsigned int lastPlayerPutCard = 0;


public :
	Border();

	virtual void setBorderCapacity(unsigned int newCap);
	virtual unsigned int getBorderCapacity() { return borderCapacity; }
	virtual unsigned int claim() = 0;

	virtual void setLastPlayerPutCard(unsigned int lastPlayerPutCard);
	virtual const unsigned int getLastPlayerPutCard() const;

	virtual std::vector<std::string> getAllCardColorInPlayerSide(unsigned int&& playerSideId);

	virtual void pushCardInBorder(std::unique_ptr<CardInterface> card);
	virtual void popCardInBorder(std::unique_ptr<CardInterface> card);

	virtual unsigned int getMaxCapacityInPlayerSide() const;

	virtual void setFirstPlayerSide(std::unique_ptr<PlayerSide> playerSide);
	virtual void setSecondPlayerSide(std::unique_ptr<PlayerSide> playerSide);

	virtual void printBorder();

	virtual void printFirtPlayerSideCardByIndex(unsigned int&& index);
	virtual void printSecondPlayerSideCardByIndex(unsigned int&& index);
	
	virtual void putCardInFirstPlayerSide(std::unique_ptr<CardInterface> card);
	virtual void putCardInSecondPlayerSide(std::unique_ptr<CardInterface> card);

	virtual void printFirstPlayerBorderSide();
	virtual void printSecondPlayerBorderSide();

	virtual const unsigned int getFirstPlayerSidePutCardIndex() const;
	virtual const unsigned int getSecondPlayerSidePutCardIndex() const;

	virtual std::unordered_map<std::string, unsigned int> fillPlayerRevendicateMap(unsigned int&& playerSideId);

	virtual CardInterface* getCardInPlayerSide(unsigned int&& playerSideId, unsigned int&& indexCard);

	virtual const unsigned int determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination);
	virtual const unsigned int getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map);

	virtual std::vector<unsigned int> getFirstPlayerSideAllCardNumber();
	virtual std::vector<unsigned int> getSecondPlayerSideAllCardNumber();

	const unsigned int getBorderCapacity() const;

private :

	void fillPlayerSides();

};

#endif