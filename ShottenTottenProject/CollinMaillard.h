#ifndef COLLIN_MAILLARD_H
#define COLLIN_MAILLARD_H

#include "BorderDecorator.h"


class CollinMaillard : public BorderDecorator
{

public :

	unsigned int claim() override;
};

#endif