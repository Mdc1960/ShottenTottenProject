#ifndef SUM_COMBINATION_H
#define SUM_COMBINATION_H

#include "Combination.h"

template <class T>
class SumCombination : public Combination<T>
{

public:

	unsigned int playerCombination(std::initializer_list<std::string> list) override;
};

template<class T>
inline unsigned int SumCombination<T>::playerCombination(std::initializer_list<std::string> list)
{
	return 0;
}

#endif


