#include "Game.h"

void Game::buildGameBord(unsigned int&& clanStackSize, unsigned int&& tacticStackSize)
{
	gameBord.fillBord(std::move(clanStackSize), std::move(tacticStackSize));
}

void Game::printFirstPlayerBorderSide()
{
	gameBord.printFirstPlayerBorderSide();
}

void Game::printSecondPlayerBorderSide()
{
	gameBord.printSecondPlayerBorderSide();
}

void Game::printBorderSeparator()
{
}

void Game::shuffledGameClanStack()
{
	gameBord.shuffledClanStack();
}

void Game::shuffledGameTacticStack()
{
	gameBord.shuffledTacticStack();
}

Game::Game()
{
}
