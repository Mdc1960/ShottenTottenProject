#ifndef CARD_SET_H
#define CARD_SET_H

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include "CardInterface.h"


class CardSet
{

protected :

	std::vector<std::unique_ptr<CardInterface>> cardCollection;

public :

	virtual std::size_t size() = 0;
	virtual void pop() = 0;
	virtual void push(std::unique_ptr<CardInterface> card) = 0;
	virtual void printCardSet() = 0;
	virtual void fillCardSet() = 0;
	virtual ~CardSet(){}

};

#endif