#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "Observable.h"

class Observable;

class Observer {

public:
	virtual void update(Observable* observable) = 0;
	virtual ~Observer(){}
};



#endif