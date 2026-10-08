#ifndef COLOR_SEQUENCE_COMBINATION_H
#define COLOR_SEQUENCE_COMBINATION_H

#include "ColorCombination.h"
#include "SequenceCombination.h"

/** 
 * @brief A class representing a color sequence combination.
 * This class inherits from ColorCombination and SequenceCombination, providing an interface for color sequence combinations in the game.
 * Template parameters T and U represent the types of elements in the color and sequence combinations, respectively.
 */
template <class T, class U>
class ColorSequenceCombination : public ColorCombination<T>, public SequenceCombination<U>
{

protected :

	/** 
	 * @brief Determines the player's combination based on the provided list.
	 * @param list A vector containing the elements of the combination.
	 * @return An unsigned integer representing the player's combination score.
	 */
	virtual unsigned int playerCombination(std::vector<T> list) override;


public :

	/** 
	 * @brief Determines the player's combination based on the provided lists.
	 * @param firstList A vector containing the elements of the color combination.
	 * @param secondList A vector containing the elements of the sequence combination.
	 * @return An unsigned integer representing the player's combination score.
	 */
	virtual unsigned int playerCombinationBis(std::vector<T> firstList, std::vector<U> secondList);
	

};


template<class T, class U>
inline unsigned int ColorSequenceCombination<T, U>::playerCombination(std::vector<T> list)
{
	bool sameColor = this->cardAreSameColor(list);
	return (unsigned int)sameColor;
}

template<class T, class U>
inline unsigned int ColorSequenceCombination<T, U>::playerCombinationBis(std::vector<T> firstList, std::vector<U> secondList)
{
	unsigned int colorSequenceValue = 0;
	bool sequence = this->cardAreSequence(secondList);
	bool sameColor = this->playerCombination(firstList);

	if (sequence && sameColor) {
		colorSequenceValue = (unsigned int)Combine::COLOR_SEQUENCE_;
		
	}
	return colorSequenceValue;
}


#endif


