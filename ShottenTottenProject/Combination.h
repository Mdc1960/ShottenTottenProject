#ifndef COMBINATION_INTERFACE_H
#define COMBINATION_INTERFACE_H

#include "Border.h"


class Combination
{

public:

	virtual unsigned int playerCombination(Border* border,unsigned int&& id) = 0;
	virtual ~Combination() {}

};

#endif