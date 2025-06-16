#ifndef COLLIN_MAILLARD_H
#define COLLIN_MAILLARD_H

#include "BorderDecorator.h"


class CollinMaillard : public BorderDecorator
{
private:
	unsigned int calculerScore(unsigned int numero);

public :
	CollinMaillard(std::unique_ptr<Border> comp)
		: BorderDecorator(std::move(comp)) {};

	unsigned int claim() override;
};

#endif