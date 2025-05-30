#ifndef PLAYER_HAND_H
#define PLAYER_HAND_H

#include <iostream>
#include "CardSet.h"

static const unsigned int MAX_NUMBER_CARD_IN_HAND = 6;

class Hand : public CardSet
{

private :

	unsigned int indexToPushCard;
	unsigned int indexToPopCard;

public :

	Hand();
	~Hand(){}

	std::size_t size() override;
	void pop() override;
	void push(std::unique_ptr<CardInterface> card) override;
	void printCardSet() override;
	void fillCardSet() override;

	void setIndexToPushCard(unsigned int indexToPushCard);
	void setIndexToPopCard(const unsigned int& indexToPopCard);

	unsigned int getPushIndex() const;
	unsigned int getPopIndex() const;
	

};

#endif