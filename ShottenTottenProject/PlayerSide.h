#ifndef PLAYER_SIDE_H
#define PLAYER_SIDE_H

#include "CardSet.h"
#include "Exception.h"


#include <vector>
#include <string>
#include <initializer_list>


class PlayerSide : public CardSet
{

private :

	unsigned int capacity;

	unsigned int putCardIndex = 0;

public :

	PlayerSide();

	std::size_t size() override;
	void pop() override;
	void push(std::unique_ptr<CardInterface> card) override;
	void printCardSet() override;
	void fillCardSet() override;
	Iterator* createIterator() override;
	Iterator* createIterator(unsigned int&& pos);

	void printCardSetInReverse();
	void printCardByIndex(unsigned int&& index);

	void increaseCapacity();
	unsigned int getCapacity() const;
	void setCapacity(unsigned int& capacity);

	CardInterface* getCardByIndex(unsigned int&& indexCard);

	std::vector<std::string> getAllCardColor();

	void putCardInCardSet(std::unique_ptr<CardInterface> card);

	const unsigned int getPutCardIndex() const;

	const unsigned int getPlayerSideCombination(unsigned int&& combinationId);

	std::vector<std::string> getAllCardColorInPlayerSide();
	std::vector<unsigned int> getAllCardNumberInPlayerSide();


	class PlayerSideIterator : public Iterator {

	private:

		PlayerSide* playerSide;
		int index;

		CardInterface* currentItem() override;

		bool isDone() override;


	public:

		PlayerSideIterator(PlayerSide* playerSide, unsigned int index);


		bool hasNext() override;
		bool hasLast() override;

		CardInterface* next() override;
		CardInterface* last() override;


		PlayerSideIterator operator++();
		PlayerSideIterator operator--();
		PlayerSideIterator operator--(int);
		PlayerSideIterator operator++(int);
		bool operator==(const PlayerSideIterator& it);
		CardInterface* operator*();
		bool operator!=(const PlayerSideIterator& it);

	};

	PlayerSideIterator begin();
	PlayerSideIterator end();


};

#endif