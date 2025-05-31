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

private :

	std::vector<std::unique_ptr<PlayerSide>> firstPlayerBorderSide;
	std::vector<std::unique_ptr<PlayerSide>> secondPlayerBorderSide;
	std::vector<unsigned int> listIndexBorderClaimed;
	unsigned int			 capacity;
	BorderStatus			 status;


public :

	Border();

	void claim();

	unsigned int getMaxCapacityInPlayerSide(unsigned int&& indexPlayerSides) const;

	void increasePlayerSideBorderCapacity(unsigned int&& indexPlayerSides);

	void printFirstPlayerBorderSide();
	void printSecondPlayerBorderSide();

private :

	void fillPlayerSides();

};

#endif