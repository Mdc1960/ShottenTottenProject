#ifndef COLOR_SEQUENCE_COMBINATION_H
#define COLOR_SEQUENCE_COMBINATION_H

#include "ColorCombination.h"
#include "SequenceCombination.h"

template <class T, class U>
class ColorSequenceCombination : public ColorCombination<T>, public SequenceCombination<U>
{

protected :

	virtual unsigned int playerCombination(std::initializer_list<T> list) override;


public :

	virtual unsigned int playerCombinationBis(std::initializer_list<T> firstList, std::initializer_list<U> secondList);
	

};


template<class T, class U>
inline unsigned int ColorSequenceCombination<T, U>::playerCombination(std::initializer_list<T> list)
{
	bool sameColor = this->cardAreSameColor(list);
	return (unsigned int)sameColor;
}

template<class T, class U>
inline unsigned int ColorSequenceCombination<T, U>::playerCombinationBis(std::initializer_list<T> firstList, std::initializer_list<U> secondList)
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


