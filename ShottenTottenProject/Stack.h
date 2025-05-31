#ifndef CARD_STACK_H
#define CARD_STACK_H

#include <iostream>
#include "CardSet.h"
#include "GameUtil.h"

static const unsigned int MAX_NUMBER_CARD_IN_STACK = 56;

class Stack : public CardSet
{

private :

	unsigned int capacity;

	void push(std::unique_ptr<CardInterface> card) override;
	

public :

	Stack(unsigned int&& capacity);

	std::size_t size() override;
	void pop() override;
	void fillCardSet() override;
	void printCardSet() override;
	std::unique_ptr<CardInterface> popAndGetBackCard();
	void shuffledStack();
	

};

#endif