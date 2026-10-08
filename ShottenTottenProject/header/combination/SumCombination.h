/**
 * @file SumCombination.h
 * Declares a combination that reports the sum-combination value when all
 * elements in a player's list are non-NULL.
 */
#ifndef SUM_COMBINATION_H
#define SUM_COMBINATION_H

#include "Combination.h"

/**
 * Combination implementation that identifies a complete player combination
 * as a sum combination.
 *
 * @tparam T the type of elements stored in the combination
 */
template <class T>
class SumCombination : public Combination<T>
{

public:

	/**
	 * Determines whether every element in the supplied list is non-NULL.
	 *
	 * @param list elements of the player's combination
	 * @return {@code Combine::SUM_} when every element is non-NULL, or 0
	 *         otherwise
	 */
	unsigned int playerCombination(std::vector<T> list) override;
};

/**
 * Counts the non-NULL elements in the list and returns the sum-combination
 * value only when that count equals the list's size.
 *
 * @tparam T the type of elements stored in the combination
 * @param list elements of the player's combination
 * @return {@code Combine::SUM_} when every element is non-NULL, or 0
 *         otherwise
 */
template<class T>
inline unsigned int SumCombination<T>::playerCombination(std::vector<T> list)
{
	unsigned int sumValue = 0;
	unsigned int sumCounter = 0;
	for (auto it : list) {
		if (it != NULL) {
			sumCounter++;
		}
	}
	if (sumCounter == list.size()) {
		sumValue = (unsigned int)Combine::SUM_;
	}
	return sumValue;
}

#endif
