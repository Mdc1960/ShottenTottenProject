#ifndef COLOR_SEQUENCE_COMBINATION_H
#define COLOR_SEQUENCE_COMBINATION_H

#include "ColorCombination.h"
#include "SequenceCombination.h"

template <class T, class U>
class ColorSequenceCombination : public ColorCombination<T>, public SequenceCombination<U>
{

public :

	virtual unsigned int playerCombination(std::initializer_list<T> list) override;


	
	//bool cardAreSequence(std::initializer_list<unsigned int> list);
	

};


template<class T, class U>
inline unsigned int ColorSequenceCombination<T, U>::playerCombination(std::initializer_list<T> list)
{
	return 0;
}


#endif


