#ifndef CARD_SET_H
#define CARD_SET_H

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include "CardInterface.h"
#include "IteratorInterface.h"

class Iterator;

/** 
 * @brief A class representing a set of cards.
 * This class manages a collection of cards and provides an interface for iterating over them.
 */
class CardSet
{

protected :

	/** 
	 * @brief A collection of unique pointers to CardInterface objects.
	 */
	std::vector<std::unique_ptr<CardInterface>> cardCollection;

public :

	/** 
	 * @brief Creates an iterator for the card set.
	 * @return A pointer to an Iterator object for the card set.
	 */
	virtual Iterator* createIterator() = 0;

	/** 
	 * @brief Gets the size of the card set.
	 * @return The number of cards in the set.
	 */
	virtual std::size_t size() = 0;

	/** 
	 * @brief Removes the last card from the set.
	 */
	virtual void pop() = 0;

	/** 
	 * @brief Adds a card to the set.
	 * @param card A unique pointer to the CardInterface object to add.
	 */
	virtual void push(std::unique_ptr<CardInterface> card) = 0;

	/** 
	 * @brief Prints the card set.
	 */
	virtual void printCardSet() = 0;

	/** 
	 * @brief Fills the card set with cards.
	 */
	virtual void fillCardSet() = 0;

	/** 
	 * @brief Destructor for the CardSet class.
	 */
	virtual ~CardSet(){}

};

#endif