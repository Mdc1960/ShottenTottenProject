#ifndef PLAYER_SIDE_H
#define PLAYER_SIDE_H

#include "CardSet.h"


class PlayerSide : public CardSet
{

private :

	unsigned int capacity;

public :

	PlayerSide();

	std::size_t size() override;
	void pop() override;
	void push(std::unique_ptr<CardInterface> card) override;
	void printCardSet() override;
	void fillCardSet() override;
	void increaseCapacity();
	unsigned int getCapacity() const;

};

#endif