#include "Game.h"

Game::Game() : gameMode(GameMode::BASE)
{
	buildGameBord(std::move(56), std::move(12));
}

void Game::putCardInBordersColumnUsingPlayerId(std::unique_ptr<CardInterface> card, unsigned int&& playerId, unsigned int&& columnIndex)
{
	try {
		gameBord.putCardInBorderByPlayerIdAndColumnIndex(std::move(card), std::move(playerId), std::move(columnIndex));
	}
	catch (GameException& exp) {
		std::cout << "\aError while puting card : " << exp.what() << std::endl;
	}
	
}


void Game::buildGameBord(unsigned int&& clanStackSize, unsigned int&& tacticStackSize)
{
	gameBord.createBordStacks(std::move(clanStackSize), std::move(tacticStackSize));//Create Stacts Cards.
	gameBord.printBorders();
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

			try {

				integerMode = std::stoi(stringMode);

				std::cout << "Mode : " << std::stoi(stringMode) << std::endl;

				if (integerMode <= 0 || integerMode > 3) {
					throw new GameException("The value you set is out of range.");
				}

				switch (integerMode) {
				case 1:
					gameMode = GameMode::BASE;
					break;
				case 2:
					gameMode = GameMode::TACTIC;
					break;
				case 3:
					gameMode = GameMode::EXPERT;
					break;
				default:
					break;

				}

				if (gameMode == GameMode::BASE || gameMode == GameMode::TACTIC || gameMode == GameMode::EXPERT) {
					printMode();
					isModeResponseCorrect = true;
				}
				else {
					std::cout << "\a" << std::endl;
					std::cerr << "The integer isn't between 1 and 3 ! try again" << std::endl;
				}

			}
			catch (const std::invalid_argument& arg) {
				std::cout << "\a" << std::endl;
				std::cout << "Invalide choice try again !! : " << arg.what() << std::endl;
			}
			catch (const std::out_of_range& out) {
				std::cout << "\a" << std::endl;
				std::cout << "Invalide interger too higher try again !! : " << out.what() << std::endl;
			}
			catch (GameException& exp) {
				std::cout << "\a" << std::endl;
				std::cout << "Invalide integer : " << exp.what() << std::endl;
			}

		}
		

		while (!isPlayerChoiceCorrect) {
			std::cout << "\nNow you will set your information.\n" << std::endl;
			std::cout << "Please enter your name : ";
			std::cin >> stringFirstPlayerName;

			std::cout << "Do you want to play against : \n"
				<< " 1 - AI \n"
				<< " 2 - HUMAN PLAYER \n"
				<< std::endl;
			std::cin >> stringSecondPlayerName;

			try {
				integerPlayer = std::stoi(stringSecondPlayerName);

				if (integerPlayer < 1 || integerPlayer >= 3) {
					throw new GameException("Number should be 1 or 2.");
				}
				else {

					std::cout << "Your choice is " << integerPlayer << std::endl;
					//TODO : CREATE PLAYER AND IS OPPONENT

					// Create FirstPlayer.

					switch (integerPlayer) {
					case 1:
						//Create AI
						break;

					case 2:

						std::cout << "Please enter your opponet name : ";
						std::cin >> stringOpponentName;
						//Create Opponent
						break;

					default:
						break;
					}

					isPlayerChoiceCorrect = true;
				}

			}
			catch (const std::invalid_argument& arg) {
				std::cout << "\a" << std::endl;
				std::wcerr << "Invalid number try again. " << arg.what() << std::endl;
			}
			catch (const std::out_of_range& out) {
				std::cout << "\a" << std::endl;
				std::cerr << "Out of range try again. " << out.what() << std::endl;
			}
			catch (GameException exp) {
				std::cout << "\a" << std::endl;
				std::cout << "Number out of range : " << exp.what() << std::endl;
			}
		}

		isConfiguring = true;

	}
}

void Game::displayGameBord()
{
	gameBord.printBorders();
}

void Game::shuffledGameClanStack()
{
	gameBord.shuffledClanStack();
}

void Game::shuffledGameTacticStack()
{
	gameBord.shuffledTacticStack();
}

std::unique_ptr<CardInterface> Game::getCardFromCardClanStack()
{
	return nullptr;
}

std::unique_ptr<CardInterface> Game::getCardFromCardTackticStack()
{
	return nullptr;
}

void Game::popCardFromClanStack()
{
}

void Game::popCardFromTacticStack()
{
}

void Game::printMode()
{
	std::string mode = "";
	switch (gameMode) {
	case GameMode::BASE:
		mode = "BASE MODE";
		break;
	case GameMode::TACTIC:
		mode = "TACTIC MODE";
		break;
	case GameMode::EXPERT:
		mode = "EXPERT MODE";
		break;
	default:
		break;
	}
	std::cout << "You will play SHOTTEN TOTTEN in mode : " << mode << std::endl;
}

void Game::startGame()
{
}

void Game::showHumanPlayerHand(unsigned int&& id)
{
	switch (id) {
	case 1:
		//First Player Hand
		break;
	case 2:
		//Opponent Hand if player vs player
		break;
	default:
		break;
	}
}

void Game::setPlayerCombination(unsigned int&& combination)
{
	this->playerCombination = combination;
}

void Game::setOpponentCombination(unsigned int&& combination)
{
	this->opponentCombination = combination;
}

void Game::setAICombination(unsigned int&& combination)
{
	this->playerCombination = combination;
}

