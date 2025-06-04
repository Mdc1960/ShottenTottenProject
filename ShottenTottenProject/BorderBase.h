#ifndef BORDER_BASE_H
#define BORDER_BASE_H

#include "Border.h"

class BorderBase : public Border
{

public :

	BorderBase();

	virtual void claim() override;

};

#endif