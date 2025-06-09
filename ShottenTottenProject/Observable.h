#ifndef GAME_OBSERVABLE_H
#define GAME_OBSERVABLE_H

#include "Observer.h"

class Observer;


class Observable {

public:

	virtual void add(Observer* observer) = 0;
	virtual void remove(Observer* observer) = 0;
	virtual void notify() = 0;
	virtual ~Observable(){}

};


#endif