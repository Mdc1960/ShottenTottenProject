#include "ColorCombination.h"

unsigned int ColorCombination::playerCombination(std::initializer_list<std::string> list)
{
    unsigned int colorValue = 0;
    bool areSameColor = false;
    

    areSameColor = cardAreSameColor<std::string>(list);

    if (areSameColor) {
        colorValue = (unsigned int)Combine::COLOR_;
        return colorValue;
    }
    else {
        return colorValue;
    }

    
}
