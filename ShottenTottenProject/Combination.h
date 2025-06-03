#ifndef COMBINATION_INTERFACE_H
#define COMBINATION_INTERFACE_H

#include "Border.h"


class Combination
{

public:

	virtual unsigned int playerCombination(std::initializer_list<std::string> list) = 0;
	virtual ~Combination() {}

};

#endif