#ifndef DEFAUSS_FOR_CARD_H
#define DEFAUSS_FOR_CARD_H


static const unsigned int MAX_NUMBER_CARD_IN_DEFAUSSE = 6;

#include "CardSet.h"

class Defausse : public CardSet
{

private :

	

public :

	Defausse();

	std::size_t size() override;
	virtual void push(std::unique_ptr<CardInterface> card) override;
	void printCardSet() override;

	void pop() override;
	void fillCardSet() override;
	Iterator* createIterator() override;
	

};

#endif