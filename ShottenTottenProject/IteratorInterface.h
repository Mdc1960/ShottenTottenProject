#ifndef ITERATOR_INTERFACE_H
#define ITERATOR_INTERFACE_H

#include "CardSet.h"

class Iterator {

public :

	virtual bool hasNext() = 0;
	virtual bool hasLast() = 0;
	virtual bool isDone() = 0;
	virtual CardInterface* next() = 0;
	virtual CardInterface* last() = 0;
	virtual CardInterface* currentItem() = 0;
	virtual ~Iterator(){}


};




#endif