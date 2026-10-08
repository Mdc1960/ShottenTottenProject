#ifndef COLOR_COMBINATION_H
#define COLOR_COMBINATION_H

#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>
#include "Combination.h"

/** 
 * @brief A class representing a color combination.
 * This class inherits from Combination and provides an interface for color combinations in the game.
 * Template parameter T represents the type of elements in the combination.
 */
template <class T>
class ColorCombination : public Combination<T>
{

public :

	/** 
	 * @brief Determines the player's combination based on the provided list.
	 * @param list A vector containing the elements of the combination.
	 * @return An unsigned integer representing the player's combination score.
	 */
	virtual unsigned int playerCombination(std::vector<T> list) override;

	/** 
	 * @brief Checks if all cards in the provided list are of the same color.
	 * @tparam U The type of elements in the list.
	 * @param list A vector containing the elements to check.
	 * @return true if all cards are of the same color, false otherwise.
	 */
	template<class U>
	bool cardAreSameColor(std::vector<U> list);

};

/** 
 * @brief Checks if all cards in the provided list are of the same color.
 * @tparam U The type of elements in the list.
 * @param list A vector containing the elements to check.
 * @return true if all cards are of the same color, false otherwise.
 */
template<class T>
template<class U>
inline bool ColorCombination<T>::cardAreSameColor(std::vector<U> list)
{
	size_t areSameColor = 0;

	for (auto it = list.begin(); it != list.end() - 1; it++) {
		if (*it == *(it + 1)) {
			areSameColor++;
		}

	}

	return areSameColor == list.size() - 1;
}

/** 
 * @brief Determines the player's combination based on the provided list.
 * @tparam T The type of elements in the combination.
 * @param list A vector containing the elements of the combination.
 * @return An unsigned integer representing the player's combination score.
 */
template<class T>
unsigned int ColorCombination<T>::playerCombination(std::vector<T> list)
{
	unsigned int colorValue = 0;
	bool areSameColor = false;


	areSameColor = cardAreSameColor<std::string>(list);

	if (areSameColor) {
		colorValue = (unsigned int)Combine::COLOR_;
		
	}
	return colorValue;
}





#endif

