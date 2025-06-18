#include "GameUtil.h"
#include "Exception.h"
using namespace std;

GameMode Util::gameMode = GameMode::BASE;
unsigned int Util::opponentChoiseMade = 0;


std::string Util::playerName = "";
std::string Util::opponetName = "";
std::string Util::aitName = "";

void Util::readRules() {
	cout << "=========================================================================================================================" << endl;
	cout << " WELCOME TO THE GAME! PLEASE READ THE RULES CAREFULLY!" << endl;
	cout << " CLICK 'L' TO START THE PROGRAM." << endl;
	cout << "=========================================================================================================================" << endl << endl;


	cout << R"(
 CLAN CARDS: 54 cards, numbered from 1 to 9 (the card's strength), with 6 possible colors.
Each player starts with 6 cards in hand.

 OBJECTIVE:
Win the game by:
- Controlling 5 scattered stones OR
- Controlling 3 adjacent stones.

 VOCABULARY:
- Frontier = 9 border tiles (stones)
- Draw pile = All clan cards in a stack

 NOTES:
* The player who most recently traveled to Scotland starts.
* Once a card is placed on a stone, it cannot be moved.
* A turn consists of:
  1) Play a card on a stone
  2) (Optional) Claim a stone
  3) Draw a card from the pile (unless it's empty)
* A stone can hold a maximum of 3 cards per player.

 CLAIMING A STONE:
- A player can only claim a stone if both players have 3 cards on it.
- To claim, your combination must be stronger than your opponent's.

 TACTICAL VARIANT:
- Follows the same rules as the base game, with additional tactical cards.
- Each player gets a 7-card tactical deck.
- You can draw from either the clan or tactical pile.
- You can have unlimited tactical cards in hand,
  but may only play one more tactical card than your opponent.

 TACTICAL CARD TYPES:
1) Elite Troop – behaves like a clan card.
2) Joker x2 – you choose value and color before claiming the stone.
3) Spy – clan card with value 7, choose color before claiming.
4) Shield Bearer – clan card with value 1-3, choose value and color before claiming.

 COMBINATION RANKINGS (strongest to weakest):
1) Color Run : 3 cards of the same color in consecutive values (e.g. 1-2-3 red)
2) Triple : 3 cards of the same value
3) Color : 3 cards of the same color (not necessarily in order)
4) Run : 3 consecutive values of any color
5) Sum : Any 3 cards, compared by total value

 TIEBREAKER:
- If combination strength is equal, highest sum wins.
- If sums are also equal, the first to place the third card wins.

 END OF GAME:
- A player controls 3 adjacent stones OR 5 scattered stones.
- In multi-round mode:
  - Winner gets 5 points
  - Loser earns 1 point per stone controlled
)" << endl;

	// Attente utilisateur
	string input;
	do {
		cout << "\nAppuyez sur 'L' pour lancer le jeu : ";
		getline(cin, input);
	} while (input != "L" && input != "l");

	configureGame();
}


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
					

					Util::playerName = stringFirstPlayerName;

					switch (integerPlayer) {
					case 1:
						

						Util::aitName = "AI";

						break;

					case 2:

						std::cout << "Please enter your opponet name : ";
						std::cin >> stringOpponentName;
						

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

std::string Util::transformeColorToString(Color color)
{
	switch (color) {
	case Color::RED: return "RD";
	case Color::BLUE: return "BE";
	case Color::GREEN: return "GN";
	case Color::BROWN: return "BN";
	case Color::PURPLE: return "PE";
	case Color::YELLOW: return "YW";
	default: return "Inconnu";
	}
}
