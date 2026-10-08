#ifndef SEQUENCE_COMBINATION_H
#define SEQUENCE_COMBINATION_H

#include "Combination.h"
#include <algorithm>
#include <vector>

/**
 * Evaluates whether a collection of cards forms a sequence.
 *
 * @tparam T the type of the cards evaluated by this class
 */
template <class T>
class SequenceCombination : public Combination<T>
{

public:

	/**
	 * Determines the combination value for the supplied cards.
	 *
	 * @param list the cards to evaluate
	 * @return {@code Combine::SEQUENCE_} when the cards form a sequence;
	 *         otherwise, {@code 0}
	 */
	unsigned int playerCombination(std::vector<T> list) override;

	/**
	 * Checks whether the values in the supplied list form a sequence of
	 * consecutive values. The values are checked in sorted order.
	 *
	 * @tparam U the type of the values being checked
	 * @param list the values to check
	 * @return {@code true} if the values form a sequence; otherwise, {@code false}
	 */
	template <class U>
	bool cardAreSequence(std::vector<U> list);

};

/**
 * Sorts a copy of the list and counts consecutive adjacent values.
 *
 * @tparam T the type parameter of the enclosing combination class
 * @tparam U the type of the values being checked
 * @param list the values to check
 * @return {@code true} if every adjacent pair is consecutive; otherwise,
 *         {@code false}
 */
template<class T>
template<class U>
inline bool SequenceCombination<T>::cardAreSequence(std::vector<U> list)
{
	std::vector<U> vect = list;

	std::sort(vect.begin(), vect.end());

	size_t areSequence = 0;

	for (auto it = vect.begin(); it != vect.end() - 1; it++) {
		if (*it + 1 == *(it + 1)) {
			areSequence++;
		}
	}

	return areSequence == list.size() - 1;
}

/**
 * Returns the sequence combination value if the supplied cards form a
 * sequence.
 *
 * @tparam T the type of the cards
 * @param list the cards to evaluate
 * @return the sequence combination value, or {@code 0} if the cards do not
 *         form a sequence
 */
template<class T>
inline unsigned int SequenceCombination<T>::playerCombination(std::vector<T> list)
{
	unsigned int colorValue = 0;
	bool areSameColor = false;


	areSameColor = cardAreSequence<unsigned int>(list);

	if (areSameColor) {
		colorValue = (unsigned int)Combine::SEQUENCE_;
        
	}
	return colorValue;
}


#endif
