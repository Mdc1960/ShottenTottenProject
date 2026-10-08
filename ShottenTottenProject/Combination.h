#ifndef COMBINATION_INTERFACE_H
#define COMBINATION_INTERFACE_H

#include "Border.h"
#include "GameUtil.h"
#include <vector>

/** 
 * @brief A template class representing a combination interface.
 * This class provides an interface for different types of combinations in the game.
 * Template parameter T represents the type of elements in the combination.
 */
template <class T>
class Combination
{

public:

	/** 
	 * @brief Determines the player's combination based on the provided list.
	 * @param list A vector containing the elements of the combination.
	 * @return An unsigned integer representing the player's combination score.
	 */
	virtual unsigned int playerCombination(std::vector<T> list) = 0;

	/** 
	 * @brief Destructor for the Combination class.
	 */
	virtual ~Combination() {}

};

#endif