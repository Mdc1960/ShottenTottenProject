#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "Observable.h"

class Observable;

/**
 * @brief Interface for objects that receive notifications from an Observable.
 *
 * Implementations of this class define how they respond when notified.
 */
class Observer {
public:
	/**
	 * @brief Called by an Observable to notify this observer of a change.
	 * @param observable The Observable that sent the notification.
	 */
	virtual void update(Observable* observable) = 0;

	/** @brief Virtual destructor for safe destruction through this interface. */
	virtual ~Observer() {}
};

#endif // GAME_OBSERVER_H
