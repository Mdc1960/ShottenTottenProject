#ifndef PLAYER_HAND_H
#define PLAYER_HAND_H

#include <iostream>
#include "CardSet.h"
#include "GameUtil.h"

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
	Iterator* createIterator() override;
	Iterator* createIterator(unsigned int&& pos);

	void setIndexToPushCard(unsigned int& indexToPushCard);
	void setIndexToPopCard(const unsigned int& indexToPopCard);

	unsigned int getPushIndex() const;
	unsigned int getPopIndex() const;

	void pushCardToHandByIndex(unsigned int&& indexToPush, std::unique_ptr<CardInterface>card);
	void popCardFromHandByIndex(unsigned int&& indexToPop);
	std::unique_ptr<CardInterface> popAndGetCardByIndex(unsigned int&& index);


	class HandIterator : public Iterator {

	private:

		Hand* hand;
		int index;

		CardInterface* currentItem() override;

		bool isDone() override;


	public:

		HandIterator(Hand* hand, unsigned int index);


		bool hasNext() override;
		bool hasLast() override;

		CardInterface* next() override;
		CardInterface* last() override;


		HandIterator operator++();
		HandIterator operator--();
		HandIterator operator--(int);
		HandIterator operator++(int);
		bool operator==(const HandIterator& it);
		CardInterface* operator*();
		bool operator!=(const HandIterator& it);

	};

	HandIterator begin();
	HandIterator end();

	
	

};

#endif