#ifndef BASE_BATTLE_H
#define BASE_BATTLE_H

#include "BorderDecorator.h"

/** 
 * @brief A class representing a border decorator for the Collin Maillard battle.
 * This class inherits from BorderDecorator and provides an interface for the Collin Maillard battle in the game.
 */
class CBDecorator : public BorderDecorator
{
public :

	/** 
	 * @brief Constructs a new CBDecorator object with the specified inner Border.
	 * @param comp A unique pointer to the inner Border object to be decorated.
	 */
	CBDecorator(std::unique_ptr<Border> comp)
		: BorderDecorator(std::move(comp)) {
		innerBorder->setBorderCapacity(innerBorder->getBorderCapacity() + 1);
	};

	/** 
	 * @brief Claims the border.
	 * @return The ID of the player who claimed the border.
	 */
	unsigned int claim() override;

};

#endif