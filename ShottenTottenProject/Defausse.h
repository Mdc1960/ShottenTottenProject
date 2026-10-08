#ifndef DEFAUSS_FOR_CARD_H
#define DEFAUSS_FOR_CARD_H


static const unsigned int MAX_NUMBER_CARD_IN_DEFAUSSE = 6;

#include "CardSet.h"

/** 
 * @brief A class representing a discard pile (defausse) for cards.
 * This class inherits from CardSet and provides an interface for managing a discard pile in the game.
 */
class Defausse : public CardSet
{

private :

	

public :

	/** 
	 * @brief Constructor for the Defausse class.
	 */
	Defausse();

	/** 
	 * @brief Gets the size of the discard pile.
	 * @return The number of cards in the discard pile.
	 */
	std::size_t size() override;

	/** 
	 * @brief Pushes a card onto the discard pile.
	 * @param card A unique pointer to the card to be pushed.
	 */
	virtual void push(std::unique_ptr<CardInterface> card) override;

	/** 
	 * @brief Prints the cards in the discard pile.
	 */
	void printCardSet() override;

	/** 
	 * @brief Removes a card from the discard pile.
	 */
	void pop() override;

	/** 
	 * @brief Fills the discard pile with cards.
	 */
	void fillCardSet() override;

	/** 
	 * @brief Creates an iterator for the discard pile.
	 * @return A pointer to an Iterator object for the discard pile.
	 */
	Iterator* createIterator() override;

	/** 
	 * @brief Creates an iterator for the discard pile at a specific position.
	 * @param pos The position at which to create the iterator.
	 * @return A pointer to an Iterator object for the discard pile.
	 */
	Iterator* createIterator(unsigned int&& pos);

	/** 
	 * @brief An iterator for traversing the discard pile.
	 * This class inherits from Iterator and provides an interface for iterating over the cards in the discard pile.
	 */
	class DefausseIterator : public Iterator {

	private:

		/** 
		 * @brief A pointer to the Defausse object being iterated over.
		 */
		Defausse* defausse;

		/** 
		 * @brief The current index of the iterator.
		 */
		int index;

		/** 
		 * @brief Gets the current item pointed to by the iterator.
		 * @return A pointer to the current card.
		 */
		CardInterface* currentItem() override;

		/** 
		 * @brief Checks if the iteration is done.
		 * @return True if the iteration is done, false otherwise.
		 */
		bool isDone() override;


	public:

		/** 
		 * @brief Constructor for the DefausseIterator class.
		 * @param defausse A pointer to the Defausse object being iterated over.
		 * @param index The initial index of the iterator.
		 */
		DefausseIterator(Defausse* defausse, unsigned int index);

		/** 
		 * @brief Checks if there is a next item in the iteration.
		 * @return True if there is a next item, false otherwise.
		 */
		bool hasNext() override;

		/** 
		 * @brief Checks if there is a last item in the iteration.
		 * @return True if there is a last item, false otherwise.
		 */
		bool hasLast() override;

		/** 
		 * @brief Gets the next item in the iteration.
		 * @return A pointer to the next card.
		 */
		CardInterface* next() override;

		/** 
		 * @brief Gets the last item in the iteration.
		 * @return A pointer to the last card.
		 */
		CardInterface* last() override;

		/** 
		 * @brief Overloads the increment operator.
		 * @return A reference to the incremented iterator.
		 */
		DefausseIterator operator++();

		/** 
		 * @brief Overloads the decrement operator.
		 * @return A reference to the decremented iterator.
		 */
		DefausseIterator operator--();

		/** 
		 * @brief Overloads the decrement operator with a dummy parameter.
		 * @param dummy A dummy parameter for the postfix decrement operator.
		 * @return A reference to the decremented iterator.
		 */
		DefausseIterator operator--(int);

		/** 
		 * @brief Overloads the increment operator with a dummy parameter.
		 * @param dummy A dummy parameter for the postfix increment operator.
		 * @return A reference to the incremented iterator.
		 */
		DefausseIterator operator++(int);

		/** 
		 * @brief Overloads the equality operator.
		 * @param it The iterator to compare with.
		 * @return True if the iterators are equal, false otherwise.
		 */
		bool operator==(const DefausseIterator& it);

		/** 
		 * @brief Overloads the dereference operator.
		 * @return A pointer to the current card.
		 */
		CardInterface* operator*();

		/** 
		 * @brief Overloads the inequality operator.
		 * @param it The iterator to compare with.
		 * @return True if the iterators are not equal, false otherwise.
		 */
		bool operator!=(const DefausseIterator& it);

	};

	/** 
	 * @brief Gets the beginning iterator for the discard pile.
	 * @return A DefausseIterator pointing to the beginning of the discard pile.
	 */
	DefausseIterator begin();

	/** 
	 * @brief Gets the ending iterator for the discard pile.
	 * @return A DefausseIterator pointing to the end of the discard pile.
	 */
	DefausseIterator end();

	

};

#endif