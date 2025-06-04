#ifndef SET_COMBINATION_H
#define SET_COMBINATION_H

#include "ColorCombination.h"
#include <vector>
#include <algorithm>

template <class T>
class SetCombination : public ColorCombination<T>
{

public:

	unsigned int playerCombination(std::initializer_list<T> list) override;
	bool cardAreSameValue(std::initializer_list<unsigned int> list);
};

template<class T>
unsigned int SetCombination<T>::playerCombination(std::initializer_list<T> list)
{
    return 0;
}

template<class T>
bool SetCombination<T>::cardAreSameValue(std::initializer_list<unsigned int> list)
{
    std::vector<unsigned int> vect = list;
    unsigned int areSameValue = 0;

    std::sort(vect.begin(), vect.end());

    for (unsigned int index = 0; index < vect.size() - 1; index++) {
        if (vect[index] == vect[index + 1]) {
            areSameValue++;
        }
    }

    return areSameValue;
}

#endif