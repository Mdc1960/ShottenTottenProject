#ifndef BORDER_BASE_H
#define BORDER_BASE_H

#include "Border.h"

/** 
 * @brief A base class for implementing border functionality.
 * This class inherits from the Border class and provides a concrete implementation of the claim() method.
 */
class BorderBase : public Border
{

public :

	/** 
	 * @brief Constructs a new BorderBase object. 
	 */
	BorderBase();

	/** 
	 * @brief Claims the border. 
	 * @return The index of the claimed border.
	 */
	virtual unsigned int claim() override;


};

#endif