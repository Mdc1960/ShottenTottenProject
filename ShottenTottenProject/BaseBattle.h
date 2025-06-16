#ifndef BASE_BATTLE_H
#define BASE_BATTLE_H

#include "BorderDecorator.h"


class BaseBattle : public BorderDecorator
{
public :

	unsigned int claim() override;

};

#endif