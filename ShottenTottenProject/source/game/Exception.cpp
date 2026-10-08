#include "Exception.h"

GameException::GameException(std::string&& message)
{
	this->exceptionMessage = std::move(message) + " : Code = " + std::to_string(exceptionCode);
}

GameException::GameException(std::string&& message, int&& exceptionCode)
{
	this->exceptionCode = std::move(exceptionCode);
	this->exceptionMessage = std::move(message) + " : Code = " + std::to_string(this->exceptionCode);
}

const char* GameException::what() const noexcept
{
	return this->exceptionMessage.c_str();
}
