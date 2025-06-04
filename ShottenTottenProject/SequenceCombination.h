#ifndef SEQUENCE_COMBINATION_H
#define SEQUENCE_COMBINATION_H

#include "Combination.h"
#include <algorithm>
#include <vector>

template <class T>
class SequenceCombination : public Combination<T>
{

public:

	unsigned int playerCombination(std::initializer_list<T> list) override;

	template <class U>
	bool cardAreSequence(std::initializer_list<U> list);

};

template<class T>
template<class U>
inline bool SequenceCombination<T>::cardAreSequence(std::initializer_list<U> list)
{
	std::vector<U> vect = list;

	std::sort(vect.begin(), vect.end());

	size_t areSequence = 0;

	for (auto it = vect.begin(); it != vect.end() - 1; it++) {
		if (*it + 1 == *(it + 1)) {
			areSequence++;
		}
	}

	return areSequence == list.size() - 1;
}

template<class T>
inline unsigned int SequenceCombination<T>::playerCombination(std::initializer_list<T> list)
{
	unsigned int colorValue = 0;
	bool areSameColor = false;


	areSameColor = cardAreSequence<unsigned int>(list);

	if (areSameColor) {
		colorValue = (unsigned int)Combine::SEQUENCE_;
		return colorValue;
	}
	else {
		return colorValue;
	}
}


#endif

