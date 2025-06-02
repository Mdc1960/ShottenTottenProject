#ifndef CARD_INTERFACE_H
#define CARD_INTERFACE_H

#include <string>

using namespace std;

class CardInterface{

public :

	virtual void printCard() = 0;
	virtual string getNamecard() = 0;
	virtual ~CardInterface(){}

};
#endif
