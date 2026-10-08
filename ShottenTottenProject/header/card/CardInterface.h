#ifndef CARD_INTERFACE_H
#define CARD_INTERFACE_H

#include <string>

using namespace std;

/** 
 * @brief An interface for card classes.
 * This interface defines the common methods that all card classes must implement.
 */
class CardInterface{

public :

	/** 
	 * @brief Prints the card.
	 */
	virtual void printCard() = 0;

	/** 
	 * @brief Gets the name of the card.
	 * @return The name of the card.
	 */
	virtual string getNamecard() = 0;

	/** 
	 * @brief Destructor for the CardInterface class.
	 */
	virtual ~CardInterface(){}

};
#endif
