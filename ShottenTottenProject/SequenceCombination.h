#ifndef SEQUENCE_COMBINATION_H
#define SEQUENCE_COMBINATION_H

#include "Combination.h"
#include <algorithm>
#include <vector>


class SequenceCombination : public Combination
{

public:

	unsigned int playerCombination(Border* border, unsigned int&& id) override;
	bool cardAreSequence(std::initializer_list<unsigned int> list);

};

#endif