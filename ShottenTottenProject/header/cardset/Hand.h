#ifndef PLAYER_HAND_H
#define PLAYER_HAND_H

#include <iostream>
#include "CardSet.h"
#include "GameUtil.h"

/** Maximum number of cards allowed in a hand. */
static const unsigned int MAX_NUMBER_CARD_IN_HAND = 6;

/** A card set representing a player's hand. */
class Hand : public CardSet
{
private:
	unsigned int indexToPushCard; ///< Index used to add the next card.
	unsigned int indexToPopCard;  ///< Index used to remove the next card.

public:
	/** Constructs a hand. */
	Hand();
	/** Destroys the hand. */
	~Hand() {}

	/** @return The number of cards in the hand. */
	std::size_t size() override;
	/** Removes a card from the hand. */
	void pop() override;
	/** Adds a card to the hand. @param card Card to add. */
	void push(std::unique_ptr<CardInterface> card) override;
	/** Prints the cards in the hand. */
	void printCardSet() override;
	/** Fills the hand. */
	void fillCardSet() override;
	/** @return An iterator to the beginning of the hand. */
	Iterator* createIterator() override;
	/** Creates an iterator at a specified position. @param pos Starting position. */
	Iterator* createIterator(unsigned int&& pos);

	/** Sets the push index. @param indexToPushCard New push index. */
	void setIndexToPushCard(unsigned int& indexToPushCard);
	/** Sets the pop index. @param indexToPopCard New pop index. */
	void setIndexToPopCard(const unsigned int& indexToPopCard);
	/** @return The current push index. */
	unsigned int getPushIndex() const;
	/** @return The current pop index. */
	unsigned int getPopIndex() const;

	/** Inserts a card at an index.
	 *  @param indexToPush Position at which to insert the card.
	 *  @param card Card to insert.
	 */
	void pushCardToHandByIndex(unsigned int&& indexToPush, std::unique_ptr<CardInterface> card);
	/** Removes the card at an index. @param indexToPop Position of the card to remove. */
	void popCardFromHandByIndex(unsigned int&& indexToPop);
	/** Removes and returns the card at an index.
	 *  @param index Position of the card to remove.
	 *  @return The removed card.
	 */
	std::unique_ptr<CardInterface> popAndGetCardByIndex(unsigned int&& index);
	/** Adds a card to the end of the hand. @param card Card to add. */
	void pushBackCard(std::unique_ptr<CardInterface> card);

	/** Iterator for traversing the cards in a Hand. */
	class HandIterator : public Iterator {
	private:
		Hand* hand; ///< Hand traversed by this iterator.
		int index;  ///< Current position in the hand.

		/** @return The card at the current position. */
		CardInterface* currentItem() override;
		/** @return Whether the iterator has reached the end. */
		bool isDone() override;

	public:
		/** Constructs an iterator.
		 *  @param hand Hand to traverse.
		 *  @param index Initial position.
		 */
		HandIterator(Hand* hand, unsigned int index);
		/** @return Whether a following card exists. */
		bool hasNext() override;
		/** @return Whether a preceding card exists. */
		bool hasLast() override;
		/** Advances and returns the next card. @return Next card. */
		CardInterface* next() override;
		/** Moves backward and returns the preceding card. @return Previous card. */
		CardInterface* last() override;

		/** Advances the iterator and returns it. */
		HandIterator operator++();
		/** Moves the iterator backward and returns it. */
		HandIterator operator--();
		/** Post-decrements the iterator. @return Iterator before decrement. */
		HandIterator operator--(int);
		/** Post-increments the iterator. @return Iterator before increment. */
		HandIterator operator++(int);
		/** @return true if this iterator has the same position as it. */
		bool operator==(const HandIterator& it);
		/** @return The card at the current position. */
		CardInterface* operator*();
		/** @return true if this iterator differs in position from it. */
		bool operator!=(const HandIterator& it);
	};

	/** @return An iterator to the beginning of the hand. */
	HandIterator begin();
	/** @return An iterator to the end of the hand. */
	HandIterator end();
};

#endif
