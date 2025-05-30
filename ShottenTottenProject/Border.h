#ifndef GAME_BORDER_H
#define GAME_BORDER_H

#include <iostream>
#include <utility>
#include "CardSet.h"


enum class BorderStatus{
	FIRST_PLAYER_REVENDICATE,
	SECOND_PLAYER_REVENDICATE,
	BORDER_IS_NOT_REVENDICATED
};

class Border
{

private :

	std::unique_ptr<CardSet> firstPlayerBorderItem;
	std::unique_ptr<CardSet> secondPlayerBorderItem;
	unsigned int			 capacity;
	BorderStatus			 status;


public :

	void claim();

	unsigned int getMaxCapacity() const;

	void increaseBorderCapacity();

	void addCardToFirstPlayerBorderItem(std::unique_ptr<CardInterface> card);
	void addCardToSecondPlayerBorderItem(std::unique_ptr<CardInterface> card);

};

#endif