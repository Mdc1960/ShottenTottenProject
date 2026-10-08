#ifndef CARD_STACK_H
#define CARD_STACK_H

#include <iostream>
#include "CardSet.h"
#include "GameUtil.h"
#include "Color.h"
#include "CardClan.h"

static const unsigned int MAX_NUMBER_CARD_IN_STACK = 56;

/**
 * Represents a fixed-capacity stack of cards.
 * A Stack is a specialized CardSet that stores cards in a bounded collection,
 * supports shuffling and stack-specific card creation, and can be iterated.
 */
class Stack : public CardSet
{

private :

    /**
     * Maximum number of cards this stack can contain.
     */
    unsigned int capacity;

    /**
     * Adds a card to the top of the stack.
     *
     * @param card The card to push onto the stack.
     */
    void push(std::unique_ptr<CardInterface> card) override;

    /**
     * Fills the stack with the default set of cards defined by the game.
     */
    void fillCardSet() override;

public :

    /**
     * Creates a stack with the specified capacity.
     *
     * @param capacity The maximum number of cards this stack can hold.
     */
    Stack(unsigned int&& capacity);

    /**
     * Returns the number of cards currently in the stack.
     *
     * @return The current size of the stack.
     */
    std::size_t size() override;

    /**
     * Removes the card at the top of the stack.
     */
    void pop() override;

    /**
     * Prints the current cards contained in the stack.
     */
    void printCardSet() override;

    /**
     * Creates an iterator positioned at the beginning of the stack.
     *
     * @return A pointer to a new iterator instance.
     */
    Iterator* createIterator() override;

    /**
     * Creates an iterator positioned at the specified index.
     *
     * @param index The index at which the iterator should start.
     * @return A pointer to a new iterator instance.
     */
    Iterator* createIterator(unsigned int&& index);

    /**
     * Fills the stack with cards belonging to the clan deck.
     */
    void fillClanStack();

    /**
     * Fills the stack with tactic cards.
     */
    void fillTacticStack();

    /**
     * Removes and returns the card at the back of the stack.
     *
     * @return The card removed from the back of the stack.
     */
    std::unique_ptr<CardInterface> popAndGetBackCard();

    /**
     * Randomizes the order of the cards in the stack.
     */
    void shuffledStack();

    /**
     * Creates a single clan card with the specified power and color.
     *
     * @param power The card's power value.
     * @param color The card's color.
     * @return A newly created clan card.
     */
    std::unique_ptr<CardClan> creatSingleCard(unsigned int&& power, Color&& color);

    /**
     * Iterator implementation for traversing a Stack.
     */
    class StackIterator : public Iterator
    {

    private :

        /**
         * Reference to the stack being iterated.
         */
        Stack* stack;

        /**
         * Current iteration index.
         */
        int index;

        /**
         * Returns the card at the current iterator position.
         *
         * @return The current card.
         */
        CardInterface* currentItem() override;

        /**
         * Checks whether the iterator has reached the end of the stack.
         *
         * @return true if the iterator is done; false otherwise.
         */
        bool isDone() override;

    public:

        /**
         * Creates an iterator for the given stack and starting index.
         *
         * @param stack The stack to iterate.
         * @param index The starting index of the iterator.
         */
        StackIterator(Stack* stack,unsigned int index);

        /**
         * Checks whether there is a next element available.
         *
         * @return true if a next element exists; false otherwise.
         */
        bool hasNext() override;

        /**
         * Checks whether there is a previous element available.
         *
         * @return true if a previous element exists; false otherwise.
         */
        bool hasLast() override;

        /**
         * Advances the iterator to the next card.
         *
         * @return The next card.
         */
        CardInterface* next() override;

        /**
         * Moves the iterator to the previous card.
         *
         * @return The previous card.
         */
        CardInterface* last() override;

        /**
         * Advances the iterator by one position.
         *
         * @return The updated iterator.
         */
        StackIterator operator++();

        /**
         * Moves the iterator backward by one position.
         *
         * @return The updated iterator.
         */
        StackIterator operator--();

        /**
         * Moves the iterator backward by one position using postfix notation.
         *
         * @param int Unused parameter required by postfix operator syntax.
         * @return The iterator before it was decremented.
         */
        StackIterator operator--(int);

        /**
         * Advances the iterator by one position using postfix notation.
         *
         * @param int Unused parameter required by postfix operator syntax.
         * @return The iterator before it was incremented.
         */
        StackIterator operator++(int);

        /**
         * Compares this iterator with another iterator for equality.
         *
         * @param it The iterator to compare against.
         * @return true if both iterators are equal; false otherwise.
         */
        bool operator==(const StackIterator& it);

        /**
         * Returns the current card at the iterator position.
         *
         * @return The card referenced by the iterator.
         */
        CardInterface* operator*();

        /**
         * Compares this iterator with another iterator for inequality.
         *
         * @param it The iterator to compare against.
         * @return true if the iterators are not equal; false otherwise.
         */
        bool operator!=(const StackIterator& it);

    };

    /**
     * Returns an iterator pointing to the beginning of the stack.
     *
     * @return A StackIterator at the first element.
     */
    StackIterator begin();

    /**
     * Returns an iterator representing the end of the stack.
     *
     * @return A StackIterator positioned after the last element.
     */
    StackIterator end();

};

#endif
