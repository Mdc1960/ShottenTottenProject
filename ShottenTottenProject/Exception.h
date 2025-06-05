#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

class GameException : public std::exception
{
private :
	std::string exceptionMessage;
	int exceptionCode = 0;

public :

	GameException(std::string&& message);
	GameException(std::string&& message, int&& exceptionCode);
	const char* what() const noexcept override;

};

#endif