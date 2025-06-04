#ifndef COLOR_COMBINATION_H
#define COLOR_COMBINATION_H

#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>
#include "Combination.h"

template <class T>
class ColorCombination : public Combination<T>
{

public :

	virtual unsigned int playerCombination(std::initializer_list<T> list) override;

	template<class U>
	bool cardAreSameColor(std::initializer_list<U> list);

};

template<class T>
template<class U>
inline bool ColorCombination<T>::cardAreSameColor(std::initializer_list<U> list)
{
	size_t areSameColor = 0;

	for (auto it = list.begin(); it != list.end() - 1; it++) {
		if (*it == *(it + 1)) {
			areSameColor++;
		}

	}

	return areSameColor == list.size() - 1;
}


template<class T>
unsigned int ColorCombination<T>::playerCombination(std::initializer_list<T> list)
{
	unsigned int colorValue = 0;
	bool areSameColor = false;


	areSameColor = cardAreSameColor<std::string>(list);

	if (areSameColor) {
		colorValue = (unsigned int)Combine::COLOR_;
		
	}
	return colorValue;
}





#endif

