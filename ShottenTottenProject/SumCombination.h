#ifndef SUM_COMBINATION_H
#define SUM_COMBINATION_H

#include "Combination.h"

template <class T>
class SumCombination : public Combination<T>
{

public:

	unsigned int playerCombination(std::initializer_list<T> list) override;
};

template<class T>
inline unsigned int SumCombination<T>::playerCombination(std::initializer_list<T> list)
{
	unsigned int sumValue = 0;
	unsigned int sumCounter = 0;
	for (auto it : list) {
		if (it != NULL) {
			sumCounter++;
		}
	}
	if (sumCounter == list.size()) {
		sumValue = (unsigned int)Combine::SUM_;
	}
	return sumValue;
}

#endif


