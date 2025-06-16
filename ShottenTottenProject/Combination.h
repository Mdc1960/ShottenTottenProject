#ifndef COMBINATION_INTERFACE_H
#define COMBINATION_INTERFACE_H

#include "Border.h"
#include "GameUtil.h"
#include <vector>

template <class T>
class Combination
{

public:

	
	virtual unsigned int playerCombination(std::vector<T> list) = 0;
	virtual ~Combination() {}

};

#endif