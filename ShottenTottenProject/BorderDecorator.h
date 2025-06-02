#ifndef BORDER_DECORATOR_H
#define BORDER_DECORATOR_H

#include "Border.h"

class BorderDecorator : public Border
{

private :

	std::unique_ptr<Border> innerBorder;

};

#endif