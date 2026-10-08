#include "CBDecorator.h"

unsigned int CBDecorator::claim()
{
	return innerBorder->claim();
}

