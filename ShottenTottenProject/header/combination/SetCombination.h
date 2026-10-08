#ifndef SET_COMBINATION_H
#define SET_COMBINATION_H

#include "ColorCombination.h"
#include <vector>
#include <algorithm>

/**
 * @brief Evaluates whether cards form a set combination.
 * @tparam T The card type used by the base ColorCombination class.
 */
template <class T>
class SetCombination : public ColorCombination<T>
{

protected:
	/**
	 * @brief Checks whether the cards have the same color.
	 * @param list Cards to check.
	 * @return 1 if the cards have the same color, or 0 otherwise.
	 */
	unsigned int playerCombination(std::vector<T> list) override;

public:
	/**
	 * @brief Checks whether any card values in the list are equal.
	 * @param list Card values to check.
	 * @return true if at least two values are equal; otherwise, false.
	 */
	bool cardAreSameValue(std::vector<unsigned int> list);

	/**
	 * @brief Checks both the card-value and card-color conditions for a set.
	 * @param firstList Cards used for the color check.
	 * @param secondList Card values used for the equal-value check.
	 * @return Combine::SET_ if both conditions are met; otherwise, 0.
	 */
	unsigned int playerCobinationBis(std::vector<T> firstList, std::vector<unsigned int> secondList);
};

/** @copydoc SetCombination::playerCombination(std::vector<T>) */
template<class T>
unsigned int SetCombination<T>::playerCombination(std::vector<T> list)
{
	bool sameColor = this->cardAreSameColor(list);
	return (unsigned int)sameColor;
}

/** @copydoc SetCombination::cardAreSameValue(std::vector<unsigned int>) */
template<class T>
bool SetCombination<T>::cardAreSameValue(std::vector<unsigned int> list)
{
	std::vector<unsigned int> vect = list;
	unsigned int areSameValue = 0;

	std::sort(vect.begin(), vect.end());

	for (unsigned int index = 0; index < vect.size() - 1; index++) {
		if (vect[index] == vect[index + 1]) {
			areSameValue++;
		}
	}

	return areSameValue;
}

/** @copydoc SetCombination::playerCobinationBis(std::vector<T>, std::vector<unsigned int>) */
template<class T>
inline unsigned int SetCombination<T>::playerCobinationBis(std::vector<T> firstList, std::vector<unsigned int> secondList)
{
	unsigned int setValue = 0;
	bool areSameValue = cardAreSameValue(secondList);
	bool areSameColor = this->playerCombination(firstList);
	if (areSameValue && areSameColor) {
		setValue = (unsigned int)Combine::SET_;
	}
	return setValue;
}

#endif
