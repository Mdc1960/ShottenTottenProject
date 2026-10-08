#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const std::string& name, unsigned int id) : PlayerInterface(name,id)
{
}

void HumanPlayer::chooseBorne()
{

	while (!isBorderChooseValid) {
		std::string value;
		std::cout << "\nChoose the border you whant to put the card (" << 1 << " - " << MAX_BORDER_NUMBER_IN_BORD << ")" << std::endl;
		std::cin >> value;
		
		try {

			unsigned int borderIndex = std::stoi(value);

			if (borderIndex < 1 || borderIndex >= MAX_BORDER_NUMBER_IN_BORD + 1) {
				throw GameException("Number should be between 1 and " + std::to_string(MAX_BORDER_NUMBER_IN_BORD) + ".");
			}
			else {
				setChooseBorderIndex(borderIndex);
				setIsChooseBoredValid(true);
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
}

void HumanPlayer::claim(Bord& bord)
{

	std::string revendicateString;
	std::string revendicateStringColumn;
	bool		isRevendicateColumnCorrect = false;
	unsigned int revendicateColumn;

	while (!isRevendicateBorderValid) {

		std::cout << "\nDo you want to revendicate a boader ? (Y/N) \n" << std::endl;
		std::cin >> revendicateString;

		if (Util::equalIngnoreCase(revendicateString, "Y") || Util::equalIngnoreCase(revendicateString, "N")) {

			if (Util::equalIngnoreCase(revendicateString, "Y")) {

				do {

					std::cout << "\nWhich column of boarder do you whant to revendicate ? (1 - 9)\n";
					std::cin >> revendicateStringColumn;

					try {

						revendicateColumn = std::stoi(revendicateStringColumn);

						if (revendicateColumn < 1 || revendicateColumn > 9) {
							throw GameException("Invalid border index", 1);
						}
						else {

							setRevendicateBorderIndex(revendicateColumn);
							setIsRevendicateBorderValid(std::move(true));
							setIsPlayerWantToRevendicate(std::move(true));
							isRevendicateColumnCorrect = true;

						}

					}
					catch (const std::invalid_argument& arg) {
						std::cout << "\aInvalid column : " << arg.what() << std::endl;
					}
					catch (const std::out_of_range& out) {
						std::cout << "\aColumn out of range : " << out.what() << std::endl;
					}
					catch (GameException exp) {
						std::cout << "\aError : " << exp.what() << std::endl;
					}

				} while (!isRevendicateColumnCorrect);

			}
			else {
				setIsRevendicateBorderValid(std::move(true));
			}

		}
		else {
			std::cerr << "\aThis answer is not valid !! Please try again." << std::endl;
		}

		

	}
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
	
}
