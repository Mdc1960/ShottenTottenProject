#ifndef SET_COMBINATION_H
#define SET_COMBINATION_H

#include "ColorCombination.h"
#include <vector>
#include <algorithm>


class SetCombination : public ColorCombination
{

public:

	unsigned int playerCombination(Border* border, unsigned int&& id) override;
	bool cardAreSameValue(std::initializer_list<unsigned int> list);
};

#endif