#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

/** 
 * @brief A class representing a game exception.
 * This class inherits from std::exception and provides an interface for handling exceptions in the game.
 */
class GameException : public std::exception
{
private :

	/** 
	 * @brief The message associated with the exception.
	 */
	std::string exceptionMessage;

	/** 
	 * @brief The code associated with the exception.
	 */
	int exceptionCode = 0;

public :

	/** 
	 * @brief Constructor for the GameException class.
	 * @param message The message associated with the exception.
	 */
	GameException(std::string&& message);

	/** 
	 * @brief Constructor for the GameException class with an exception code.
	 * @param message The message associated with the exception.
	 * @param exceptionCode The code associated with the exception.
	 */
	GameException(std::string&& message, int&& exceptionCode);

	/** 
	 * @brief Gets the message associated with the exception.
	 * @return A pointer to the message string.
	 */
	const char* what() const noexcept override;

};

#endif