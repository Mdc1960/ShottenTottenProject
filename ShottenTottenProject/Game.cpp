#include "Game.h"

void Game::buildGameBord(unsigned int&& clanStackSize, unsigned int&& tacticStackSize)
{
	gameBord.fillBord(std::move(clanStackSize), std::move(tacticStackSize));

	printFirstPlayerBorderSide();
	printBorderSeparator();
	printSecondPlayerBorderSide();
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

void Game::startConfiguration()
{
	std::string stringMode = "";
	std::string stringFirstPlayerName = "";
	std::string stringSecondPlayerName = "";
	std::string stringOpponentName = "";

	unsigned int integerMode = 0;
	unsigned int integerPlayer = 0;

	bool isModeResponseCorrect = false;
	bool isPlayerChoiceCorrect = false;

	std::cout << "WELCOM INTO SCHOTTEN TOTTEN WOLRD !!!" << std::endl;

	while (!isConfiguring) {

		while (!isModeResponseCorrect) {
			std::cout << "\nWhat mode do yo want to play : " << std::endl;
			std::cout
				<< "  1 - BASE     MODE \n"
				<< "  2 - TACTICAL MODE \n"
				<< "  3 - EXPERT   MODE \n"
				<< std::endl;

			std::cin >> stringMode;
		}

	}
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
