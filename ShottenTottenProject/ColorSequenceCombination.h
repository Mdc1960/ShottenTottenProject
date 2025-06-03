#ifndef COLOR_SEQUENCE_COMBINATION_H
#define COLOR_SEQUENCE_COMBINATION_H

#include "ColorCombination.h"
#include "SequenceCombination.h"

class ColorSequenceCombination : public ColorCombination, public SequenceCombination
{

public :

	virtual unsigned int playerCombination(Border* border, unsigned int&& id) override;

	
	//bool cardAreSequence(std::initializer_list<unsigned int> list);
	

};

#endif