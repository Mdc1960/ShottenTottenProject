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

	PlayerSide firstPlayerBorderSide;
	PlayerSide secondPlayerBorderSide;
	std::vector<unsigned int> listIndexBorderClaimed;
	BorderStatus			 status;


public :

	Border();

	virtual void claim() = 0;

	void pushCardInBorder(std::unique_ptr<CardInterface> card);
	void popCardInBorder(std::unique_ptr<CardInterface> card);

	unsigned int getMaxCapacityInPlayerSide(unsigned int&& indexPlayerSides) const;

	

	void printFirstPlayerBorderSide();
	void printSecondPlayerBorderSide();

private :

	void fillPlayerSides();

};

#endif