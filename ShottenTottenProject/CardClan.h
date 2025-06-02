#pragma once

#include "CardInterface.h"
#include <iostream>

/*!
* CardClan
*/
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
	
	CardClan(std::string name){
		this->name = name;
		counter++;
	}

	void setName(std::string name) {
		this->name = name;
	}

	std::string getName() const {
		return name;
	}
	
	void show();

	void printCard() override;
};

