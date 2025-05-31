#ifndef REVENDICATE_Border8H
#define REVENDICATE_Border8H

#include "Phase.h"


class RevendicateBorder : public Phase
{

public :

	void acceptPlayer(PlayerInterface* player) override;
};

#endif