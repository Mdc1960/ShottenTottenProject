#ifndef BASE_BATTLE_H
#define BASE_BATTLE_H

#include "BorderDecorator.h"


class CBDecorator : public BorderDecorator
{
public :
	CBDecorator(std::unique_ptr<Border> comp)
		: BorderDecorator(std::move(comp)) {
		innerBorder->setBorderCapacity(innerBorder->getBorderCapacity() + 1);
	};
	unsigned int claim() override;

};

#endif