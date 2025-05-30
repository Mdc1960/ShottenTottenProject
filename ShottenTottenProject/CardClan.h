#pragma once

#include "CardInterface.h"
#include <iostream>


class CardClan : public CardInterface
{

public :

	static unsigned int counter;
	std::string name;

public :

	CardClan(){
		name = "";
		counter++;
	}

	void setName(std::string name) {
		this->name = name;
	}

	std::string getName() const {
		return name;
	}
	
	

	void printCard() override;
};

