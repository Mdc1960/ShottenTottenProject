#ifndef BASE_BATTLE_H
#define BASE_BATTLE_H

#include "BorderDecorator.h"


class BaseBattle : public BorderDecorator
{
public :

	void claim() override;

};

#endif