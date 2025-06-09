#include "GameUtil.h"
#include "Exception.h"

GameMode Util::gameMode = GameMode::BASE;
unsigned int Util::opponentChoiseMade = 0;


std::string Util::playerName = "";
std::string Util::opponetName = "";
std::string Util::aitName = "";

const bool Util::equalIngnoreCase(std::string& first, std::string&& second)
{
    return std::equal(first.begin(), first.end(), second.begin(), second.end(),
        [](char a, char b) {
            return std::tolower(a) == std::tolower(b);
        });
}

void Util::configureGame()
{
    
	std::string stringMode = "";
	std::string stringFirstPlayerName = "";
	std::string stringSecondPlayerChoice = "";
	std::string stringOpponentName = "";

	unsigned int integerMode = 0;
	unsigned int integerPlayer = 0;

	bool isModeResponseCorrect = false;
	bool isPlayerChoiceCorrect = false;

	bool isConfiguring = false;

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
					throw GameException("The value you set is out of range.");
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
			std::cout << "\nNow you will set your information. Your are the first who travel recently around ECOSS!!!\n" << std::endl;
			std::cout << "Please enter your name : ";
			std::cin >> stringFirstPlayerName;

			std::cout << "Do you want to play against : \n"
				<< " 1 - AI \n"
				<< " 2 - HUMAN PLAYER \n"
				<< std::endl;
			std::cin >> stringSecondPlayerChoice;

			try {
				integerPlayer = std::stoi(stringSecondPlayerChoice);

				if (integerPlayer < 1 || integerPlayer >= 3) {
					throw GameException("Number should be 1 or 2.");
				}
				else {

					std::cout << "Your choice is " << integerPlayer << std::endl;
					Util::opponentChoiseMade = integerPlayer;
					//TODO : CREATE PLAYER AND IS OPPONENT

					// Create FirstPlayer.
					

					Util::playerName = stringFirstPlayerName;

					switch (integerPlayer) {
					case 1:
						//Create AI

						Util::aitName = "AI";

						break;

					case 2:

						std::cout << "Please enter your opponet name : ";
						std::cin >> stringOpponentName;
						//Create Opponent

						Util::opponetName = stringOpponentName;

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

void Util::printMode()
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
