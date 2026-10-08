#ifndef GAME_OBSERVABLE_H
#define GAME_OBSERVABLE_H

#include "Observer.h"

class Observer;

/**
 * Defines the interface for an object that can be observed.
 * Implementations manage observers and notify them when the observable's
 * state changes.
 */
class Observable {

public:
	/**
	 * Registers an observer to receive notifications.
	 * @param observer Pointer to the observer to register.
	 */
	virtual void add(Observer* observer) = 0;

	/**
	 * Unregisters an observer so it no longer receives notifications.
	 * @param observer Pointer to the observer to unregister.
	 */
	virtual void remove(Observer* observer) = 0;

	/**
	 * Notifies all registered observers of a change.
	 */
	virtual void notify() = 0;

	/**
	 * Destroys the observable.
	 */
	virtual ~Observable() {}
};

#endif
