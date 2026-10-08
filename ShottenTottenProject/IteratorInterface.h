#ifndef ITERATOR_INTERFACE_H
#define ITERATOR_INTERFACE_H

#include "CardSet.h"

/**
 * Defines the interface for iterating over a collection of cards.
 *
 * Implementations provide operations to move forward and backward through
 * the collection and to inspect the current card.
 */
class Iterator {

public:

	/**
	 * Checks whether a card is available after the current position.
	 * @return {@code true} if another card can be obtained with {@link #next()},
	 *         otherwise {@code false}.
	 */
	virtual bool hasNext() = 0;

	/**
	 * Checks whether a card is available before the current position.
	 * @return {@code true} if another card can be obtained with {@link #last()},
	 *         otherwise {@code false}.
	 */
	virtual bool hasLast() = 0;

	/**
	 * Checks whether iteration has reached its completed state.
	 * @return {@code true} if iteration is done, otherwise {@code false}.
	 */
	virtual bool isDone() = 0;

	/**
	 * Advances the iterator and returns the next card.
	 * @return the next card, or {@code nullptr} if no next card is available.
	 */
	virtual CardInterface* next() = 0;

	/**
	 * Moves the iterator backward and returns the previous card.
	 * @return the previous card, or {@code nullptr} if no previous card is available.
	 */
	virtual CardInterface* last() = 0;

	/**
	 * Returns the card at the iterator's current position.
	 * @return the current card, or {@code nullptr} if there is no current card.
	 */
	virtual CardInterface* currentItem() = 0;

	/** Destroys the iterator. */
	virtual ~Iterator() {}
};

#endif
