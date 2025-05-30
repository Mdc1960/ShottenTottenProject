#pragma once

#include "CardInterface.h"


class CardClan : public CardInterface
{

public :

	static unsigned int counter;

public :

	CardClan(){
		counter++;
	}
	
	

	void printCard() override;
};

