#ifndef COLOR_COMBINATION_H
#define COLOR_COMBINATION_H

#include <iostream>
#include <initializer_list>
#include "Combination.h"

class ColorCombination : public Combination
{

private :

	unsigned int capacity = 0;

public :

	virtual unsigned int playerCombination(Border* border, unsigned int&& id) override;

	template<class T>
	bool cardAreSameColor(std::initializer_list<T> list);

};



template<class T>
inline bool ColorCombination::cardAreSameColor(std::initializer_list<T> list)
{
	size_t areSameColor = 0;

	for (auto it = list.begin(); it != list.end()-1; it++) {
		if (*it == *(it + 1)) {
			areSameColor++;
		}
		
	}

	return areSameColor == list.size() - 1;
}

#endif