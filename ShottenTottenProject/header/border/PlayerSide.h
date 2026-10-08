/**
 * @file PlayerSide.h
 * @brief Declares a player's card side and its iterator.
 */

#ifndef PLAYER_SIDE_H
#define PLAYER_SIDE_H

#include "CardSet.h"
#include "Exception.h"

#include <vector>
#include <string>
#include <initializer_list>

/**
 * @brief A card set representing the cards on one player's side.
 *
 * Extends CardSet with capacity management, card-placement tracking,
 * indexed card access, and iteration in both directions.
 */
class PlayerSide : public CardSet
{

private:

	/** Maximum number of cards this side can hold. */
	unsigned int capacity;

	/** Index at which the next card is to be placed. */
	unsigned int putCardIndex = 0;

public:

	/** Constructs an empty player side. */
	PlayerSide();

	/** @return The number of cards currently in the side. */
	std::size_t size() override;

	/** Removes a card from the side. */
	void pop() override;

	/** Adds a card to the side, taking ownership of it. */
	void push(std::unique_ptr<CardInterface> card) override;

	/** Prints the cards in the side. */
	void printCardSet() override;

	/** Fills the side with cards. */
	void fillCardSet() override;

	/** @return A newly created iterator positioned at the beginning. */
	Iterator* createIterator() override;

	/**
	 * Creates an iterator positioned at the specified index.
	 * @param pos Initial card index for the iterator.
	 * @return A newly created iterator.
	 */
	Iterator* createIterator(unsigned int&& pos);

	/** Prints the cards in reverse order. */
	void printCardSetInReverse();

	/**
	 * Prints the card at the specified index.
	 * @param index Index of the card to print.
	 */
	void printCardByIndex(unsigned int&& index);

	/** Increases the side's capacity. */
	void increaseCapacity();

	/** @return The current card capacity. */
	unsigned int getCapacity() const;

	/** Sets the side's capacity. @param newcap The new capacity. */
	void setCapacity(unsigned int newcap) { capacity = newcap; }

	/**
	 * Retrieves the card at the specified index.
	 * @param indexCard Index of the requested card.
	 * @return A non-owning pointer to the card.
	 */
	CardInterface* getCardByIndex(unsigned int&& indexCard);

	/** @return The colors of the cards in this side. */
	std::vector<std::string> getAllCardColor();

	/** Adds a card to this side and updates placement tracking. */
	void putCardInCardSet(std::unique_ptr<CardInterface> card);

	/** @return The index used for the next card placement. */
	const unsigned int getPutCardIndex() const;

	/**
	 * Retrieves the combination value identified by the given ID.
	 * @param combinationId Identifier of the requested combination.
	 * @return The combination value.
	 */
	const unsigned int getPlayerSideCombination(unsigned int&& combinationId);

	/** @return The colors of all cards in this player side. */
	std::vector<std::string> getAllCardColorInPlayerSide();

	/** @return The numbers of all cards in this player side. */
	std::vector<unsigned int> getAllCardNumberInPlayerSide();

	/** Iterator for traversing the cards in a PlayerSide. */
	class PlayerSideIterator : public Iterator {

	private:

		/** Player side traversed by this iterator; not owned. */
		PlayerSide* playerSide;

		/** Index of the iterator's current position. */
		int index;

		/** @return The card at the current iterator position. */
		CardInterface* currentItem() override;

		/** @return Whether the iterator has reached its end. */
		bool isDone() override;


	public:

		/**
		 * Constructs an iterator for a player side.
		 * @param playerSide Side to traverse; the iterator does not own it.
		 * @param index Initial card index.
		 */
		PlayerSideIterator(PlayerSide* playerSide, unsigned int index);

		/** @return Whether a next card is available. */
		bool hasNext() override;

		/** @return Whether a previous card is available. */
		bool hasLast() override;

		/** Advances the iterator and returns the next card. */
		CardInterface* next() override;

		/** Moves the iterator backward and returns the preceding card. */
		CardInterface* last() override;

		/** Advances the iterator and returns the updated iterator. */
		PlayerSideIterator operator++();

		/** Moves the iterator backward and returns the updated iterator. */
		PlayerSideIterator operator--();

		/** Moves the iterator backward and returns its previous state. */
		PlayerSideIterator operator--(int);

		/** Advances the iterator and returns its previous state. */
		PlayerSideIterator operator++(int);

		/** @return Whether both iterators refer to the same position. */
		bool operator==(const PlayerSideIterator& it);

		/** @return The card at the current iterator position. */
		CardInterface* operator*();

		/** @return Whether the iterators refer to different positions. */
		bool operator!=(const PlayerSideIterator& it);

	};

	/** @return An iterator positioned at the first card. */
	PlayerSideIterator begin();

	/** @return An iterator representing the end position. */
	PlayerSideIterator end();


};

#endif
