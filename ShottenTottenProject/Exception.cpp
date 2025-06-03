#include "Exception.h"

GameException::GameException(std::string&& message)
{
	this->exceptionMessage = message;
}

const char* GameException::what() const noexcept
{
	return this->exceptionMessage.c_str();
}
