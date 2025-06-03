#ifndef COLOR_SEQUENCE_COMBINATION_H
#define COLOR_SEQUENCE_COMBINATION_H

#include "ColorCombination.h"
#include "SequenceCombination.h"

class ColorSequenceCombination : public ColorCombination, public SequenceCombination
{

public :

	virtual unsigned int playerCombination(std::initializer_list<std::string> list) override;

	
	//bool cardAreSequence(std::initializer_list<unsigned int> list);
	

};

#endif