#ifndef SET_COMBINATION_H
#define SET_COMBINATION_H

#include "ColorCombination.h"
#include <vector>
#include <algorithm>

template <class T>
class SetCombination : public ColorCombination<T>
{

protected:
    unsigned int playerCombination(std::initializer_list<T> list) override;

public:
	bool cardAreSameValue(std::initializer_list<unsigned int> list);
    unsigned int playerCobinationBis(std::initializer_list<T> firstList, std::initializer_list<unsigned int> secondList);
};

template<class T>
unsigned int SetCombination<T>::playerCombination(std::initializer_list<T> list)
{
    bool sameColor = this->cardAreSameColor(list);
    return (unsigned int)sameColor;
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

template<class T>
inline unsigned int SetCombination<T>::playerCobinationBis(std::initializer_list<T> firstList, std::initializer_list<unsigned int> secondList)
{
    unsigned int setValue = 0;
    bool areSameValue = cardAreSameValue(secondList);
    bool areSameColor = this->playerCombination(firstList);
    if (areSameValue && areSameColor) {
        setValue = (unsigned int)Combine::SET_;
    }
    return setValue;
}

#endif