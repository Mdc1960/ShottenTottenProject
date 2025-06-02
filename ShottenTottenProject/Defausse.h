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
	Iterator* createIterator(unsigned int&& pos);

	class DefausseIterator : public Iterator {

	private:

		Defausse* defausse;
		int index;

		CardInterface* currentItem() override;

		bool isDone() override;


	public:

		DefausseIterator(Defausse* defausse, unsigned int index);


		bool hasNext() override;
		bool hasLast() override;

		CardInterface* next() override;
		CardInterface* last() override;


		DefausseIterator operator++();
		DefausseIterator operator--();
		DefausseIterator operator--(int);
		DefausseIterator operator++(int);
		bool operator==(const DefausseIterator& it);
		CardInterface* operator*();
		bool operator!=(const DefausseIterator& it);

	};

	DefausseIterator begin();
	DefausseIterator end();

	

};

#endif