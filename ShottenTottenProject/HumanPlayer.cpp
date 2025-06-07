#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const std::string& name, unsigned int id) : PlayerInterface(name,id)
{
}

void HumanPlayer::chooseBorne()
{
}

void HumanPlayer::claim(Bord& bord)
{
}

void HumanPlayer::chooseCard()
{

	while (!isColorChooseValid) {

		showHand();

		std::string value = "";

		std::cout << "\n\nAccording to your hand, choose a card you whant to play (0 - 5) : " << std::endl;
		std::cin >> value;

		try {
			unsigned int cardIndex = std::stoi(value);

			if (cardIndex < 0 || cardIndex >= 6) {
				throw GameException("Number should be between 0 and 5.");
			}
			else {
				setChooseCardIndex(cardIndex);
				setIsChooseColorValid(true);
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
	

	//std::cout << "You choose : " << value << std::endl;
}

void HumanPlayer::putCardInGameBordBorder(Bord& bord, std::unique_ptr<CardInterface> card, const unsigned int& chooseBorderIndex)
{
}
