#ifndef COMBINATION_INTERFACE_H
#define COMBINATION_INTERFACE_H

#include "Border.h"

template <class T>
class Combination
{

public:

	
	virtual unsigned int playerCombination(std::initializer_list<T> list) = 0;
	virtual ~Combination() {}

};

#endif