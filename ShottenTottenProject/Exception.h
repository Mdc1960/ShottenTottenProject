#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

class GameException : public std::exception
{
private :
	std::string exceptionMessage;

public :

	GameException(std::string&& message);
	const char* what() const noexcept override;

};

#endif