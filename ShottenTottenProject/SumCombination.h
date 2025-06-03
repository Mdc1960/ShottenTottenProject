#ifndef SUM_COMBINATION_H
#define SUM_COMBINATION_H

#include "Combination.h"


class SumCombination : public Combination
{

public:

	unsigned int playerCombination(std::initializer_list<std::string> list) override;
};

#endif