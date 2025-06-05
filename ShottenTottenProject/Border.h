#ifndef GAME_BORDER_H
#define GAME_BORDER_H

#include <iostream>
#include <utility>
#include <vector>
#include "CardSet.h"
#include "PlayerSide.h"
#include "GameUtil.h"




class Border
{

protected :

	std::unique_ptr<PlayerSide> firstPlayerBorderSide;
	std::unique_ptr<PlayerSide> secondPlayerBorderSide;
	std::vector<unsigned int> listIndexBorderClaimed;
	BorderStatus			 status;


public :

	Border();

	virtual void claim() = 0;

	std::vector<std::string> getAllCardColorInPlayerSide(unsigned int&& playerSideId);

	void pushCardInBorder(std::unique_ptr<CardInterface> card);
	void popCardInBorder(std::unique_ptr<CardInterface> card);

	unsigned int getMaxCapacityInPlayerSide() const;

	void setFirstPlayerSide(std::unique_ptr<PlayerSide> playerSide);
	void setSecondPlayerSide(std::unique_ptr<PlayerSide> playerSide);

	void printBorder();

	void printFirtPlayerSideCardByIndex(unsigned int&& index);
	void printSecondPlayerSideCardByIndex(unsigned int&& index);
	
	void putCardInFirstPlayerSide(std::unique_ptr<CardInterface> card);
	void putCardInSecondPlayerSide(std::unique_ptr<CardInterface> card);

	void printFirstPlayerBorderSide();
	void printSecondPlayerBorderSide();

	CardInterface* getCardInPlayerSide(unsigned int&& playerSideId, unsigned int&& indexCard);

private :

	void fillPlayerSides();

};

#endif