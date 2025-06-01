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
	Iterator* createIterator() override;
	Iterator* createIterator(unsigned int&& index);

	std::unique_ptr<CardInterface> popAndGetBackCard();
	void shuffledStack();

	class StackIterator : public Iterator
	{

	private :

		Stack* stack;
		unsigned int index;

		CardInterface* currentItem() override;
		
		bool isDone() override;
		

	public:

		StackIterator(Stack* stack,unsigned int index);
		

		bool hasNext() override;
		bool hasLast() override;

		CardInterface* next() override;
		CardInterface* last() override;
		

		
		void operator--(int);
		void operator++(int);
		bool operator==(const StackIterator& it);
		CardInterface* operator*();
		bool operator!=(const StackIterator& it);


	};

	

	StackIterator begin();
	StackIterator end();
	

};

#endif