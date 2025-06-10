#include "Game.h"


Game::Game() : gameMode(Util::gameMode)
{
	configuredPlayers();
	
	//startConfiguration();
	buildGameBord(std::move(54), std::move(10));
	add(&gameBord);
	//startGame();
}

void Game::putCardInBordersColumnUsingPlayerId(std::unique_ptr<CardInterface> card, unsigned int&& playerId, unsigned int&& columnIndex)
{
	try {
		gameBord.putCardInBorderByPlayerIdAndColumnIndex(std::move(card), std::move(playerId), std::move(columnIndex));
		notify();
	}
	catch (GameException& exp) {
		std::cout << "\aError while puting card : " << exp.what() << std::endl;
	}
	
}


void Game::add(Observer* observer)
{
	listObserver.push_back(observer);
}

void Game::remove(Observer* observer)
{
	listObserver.erase(std::remove(listObserver.begin(),listObserver.end(),observer), listObserver.end());
}

void Game::notify()
{
	for (auto& observer : listObserver) {
		observer->update(this);
	}
}

void Game::buildGameBord(unsigned int&& clanStackSize, unsigned int&& tacticStackSize)
{
	gameBord.createBordStacks(std::move(clanStackSize), std::move(tacticStackSize));//Create Stacts Cards.
	shuffledGameClanStack();
	shuffledGameTacticStack();
	//displayGameBord();
}


/*void Game::startConfiguration()
{
	std::string stringMode = "";
	std::string stringFirstPlayerName = "";
	std::string stringSecondPlayerChoice = "";
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
					setOpponentChoiseMade(integerPlayer);
					//TODO : CREATE PLAYER AND IS OPPONENT

					// Create FirstPlayer.
					firstPlayer = FactoryHumanPlayer().createPlayer(stringFirstPlayerName,1);
					firstPlayer->printPlayer();

					switch (integerPlayer) {
					case 1:
						//Create AI
						secondPlayer = FactoryAIPlayer().createPlayer("AI",2);
						secondPlayer->printPlayer();
						break;

					case 2:

						std::cout << "Please enter your opponet name : ";
						std::cin >> stringOpponentName;
						//Create Opponent
						secondPlayer = FactoryHumanPlayer().createPlayer(stringOpponentName, 2);
						secondPlayer->printPlayer();
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
}*/

void Game::displayGameBord()
{
	gameBord.printBorders();
}

void Game::showClanStack()
{
	gameBord.showClanStack();
}

void Game::showTacticStack()
{
	gameBord.showTacticStack();
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
	return gameBord.popAndGetCardFromClanStack();
}

std::unique_ptr<CardInterface> Game::getCardFromCardTackticStack()
{
	return gameBord.popAndGetCardFromTacticStack();
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

/*!
* Method used to start the SHOTTEN TOTTEN game.
*/
/*void Game::startGame()
{

	playPhase = std::make_shared<PlayerPlay>();

	revendicatePhase = std::make_shared<RevendicateBorder>();

	fillPlayerHandWithInitialCardsUsingId(std::move(1));
	fillPlayerHandWithInitialCardsUsingId(std::move(2));

	turn = 0;

	while (!isGameOver) {
		
		notify();

		unsigned int indexCard;
		unsigned int indexBorder;

		unsigned int aiIndexCard;
		unsigned int aiIndexBorder;

		unsigned int firstBorderSide;
		unsigned int secondBorderSide;

		unsigned int firstPlayerRevendicateBorderIndex;
		bool isFirstPlayerWantToRevendicate;

		std::unique_ptr<CardInterface> aiPlayedCard;
		std::unique_ptr<CardInterface> playerPlayedCard;

		switch (turn) {

		case 0:
			//FIRST PLAYER PLAY.

			switch (gameMode) {
			case GameMode::BASE:

				playPhase->acceptPlayer(firstPlayer.get());

				indexCard = firstPlayer->getChooseCardIndex();
				indexBorder = firstPlayer->getChooseBorderIndex();

				firstBorderSide = gameBord.getBorderSidePutCardIndex(std::move(indexBorder - 1), std::move(1));

			#ifdef _WIN32
				std::system("cls");
			#else
				std::system("clear");
			#endif



				if (firstBorderSide < 3) {

					try {

						playerPlayedCard = std::move(firstPlayer->popCardFromPlayerHandByIndex(indexCard));

						if (playerPlayedCard != nullptr) {

							gameBord.putCardInBorderByPlayerIdAndColumnIndex(std::move(playerPlayedCard), std::move(1), std::move(indexBorder - 1));

							turn = (turn + 1) % 2;

							if (!gameBord.getIsClanStackEmpty()) {
								firstPlayer->pickCardFromBordStacksAndAddInPlayerHand(gameBord);
							}

							if (Bord::numberOfCardPutInBorders >= 12) {
								notify();
								revendicatePhase->acceptPlayer(firstPlayer.get());
								isFirstPlayerWantToRevendicate = firstPlayer->getIsPlayerWantToRevendicateValue();

								if (isFirstPlayerWantToRevendicate) {
									firstPlayerRevendicateBorderIndex = firstPlayer->getRevendicateBorderIndex();

									std::cout << "First Player want to revendicate : " << firstPlayerRevendicateBorderIndex << std::endl;
								}
								firstPlayer->setIsRevendicateBorderValid(false);
							}

						}

					}
					catch (GameException exp) {
						std::cout << "Error : " << exp.what() << std::endl;
					}

				}
				else {
					std::cout << "\aPlayer '" << firstPlayer->getPlayerName() << "' the border side " << indexBorder << " is full.You cannot put card in this border side." << std::endl;
				}

				firstPlayer->setIsChooseColorValid(false);
				firstPlayer->setIsChooseBoredValid(false);

				

				break;
			case GameMode::TACTIC:
				break;
			case GameMode::EXPERT:
				break;
			default:
				break;
			}

			

				
			break;
		case 1:
			//OPPONENT PLAYER PLAY (AI/HUMAN PLAYER).
			switch (opponentChoiseMade) {

			case 1:
				//AI Play

				switch (gameMode) {
				case GameMode::BASE:

				#ifdef _WIN32
					std::system("cls");
				#else
					std::system("clear");
				#endif

					std::cout << "AI is playing" << std::endl;
					

					playPhase->acceptPlayer(secondPlayer.get());

					aiIndexCard = secondPlayer->getChooseCardIndex();
					aiIndexBorder = secondPlayer->getChooseBorderIndex();

					secondBorderSide = gameBord.getBorderSidePutCardIndex(std::move(aiIndexBorder), std::move(2));

					if (secondBorderSide < 3) {

						try {

							aiPlayedCard = std::move(secondPlayer->popCardFromPlayerHandByIndex(aiIndexCard));

							if (aiPlayedCard != nullptr) {
								gameBord.putCardInBorderByPlayerIdAndColumnIndex(std::move(aiPlayedCard), std::move(2), std::move(aiIndexBorder + 0));

								turn = (turn + 1) % 2;

								if (!gameBord.getIsClanStackEmpty()) {
									secondPlayer->pickCardFromBordStacksAndAddInPlayerHand(gameBord);
								}

							}

						}
						catch (GameException exp) {
							std::cout << "Error : " << exp.what() << std::endl;
						}

					}

					secondPlayer->setIsChooseColorValid(false);
					secondPlayer->setIsChooseBoredValid(false);

					std::cout << "Nb Put card : " << Bord::numberOfCardPutInBorders << std::endl;


					break;
				case GameMode::TACTIC:
					break;
				case GameMode::EXPERT:
					break;
				default:
					break;
				}
				
			
				
				
				break;
			case 2:
				//Human
				std::cout << "Oponnent is playing" << std::endl;
				turn = (turn + 1) % 2;
			#ifdef _WIN32
				std::system("cls");
			#else
				std::system("clear");
			#endif
				break;
			default:
				break;

			}
			
			break;
		default:
			break;
		}

	}

}*/

void Game::showHumanPlayerHand(unsigned int&& id)
{
	switch (id) {
	case 1:
		//First Player Hand
		if (dynamic_cast<HumanPlayer*>(firstPlayer.get())) {
			firstPlayer->showHand();
		}
		break;
	case 2:
		//Opponent Hand if player vs player
		if (dynamic_cast<HumanPlayer*>(secondPlayer.get())) {
			secondPlayer->showHand();
		}
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
	this->aiCombination = combination;
}

void Game::fillPlayerHandWithInitialCardsUsingId(unsigned int&& id)
{
	switch (std::move(id)) {
	case 1:
		firstPlayer->fillPlayerHandWithClanCardFronBordClanStack(gameBord);
		break;
	case 2:
		secondPlayer->fillPlayerHandWithClanCardFronBordClanStack(gameBord);
		break;
	default:
		break;

	}
}

void Game::setPlayPhase(std::shared_ptr<Phase> playPhase)
{
	this->playPhase = std::move(playPhase);
}

void Game::setRevendicatePhase(std::shared_ptr<Phase> revendicatePhase)
{
	this->revendicatePhase = std::move(revendicatePhase);
}

void Game::setOpponentChoiseMade(const unsigned int& opponentChoiseMade)
{
	this->opponentChoiseMade = opponentChoiseMade;
}

void Game::putRevendicatedBorderIndexInPlayerListById(unsigned int&& playerId, unsigned int& revendicateColumn)
{
	switch (std::move(playerId))
	{
	case 1:
		firstPlayerRevendicateBorderList.push_back(revendicateColumn);
		break;
	case 2:
		aiPlayerRevendicateBorderList.push_back(revendicateColumn);
		break;
	case 3:
		opponentPlayerRevendicateBorderList.push_back(revendicateColumn);
		break;
	default:
		break;
	}
}

std::unordered_map<std::string, unsigned int> Game::fillPlayerRevendicateMap(unsigned int& revendicateColumn, unsigned int&& playerSideId)
{
	return gameBord.fillPlayerRevendicateMap(revendicateColumn, std::move(playerSideId));
}

const unsigned int Game::getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map)
{
	unsigned int totalValue = 0;

	for (auto& m : map) {
		//std::cout << "map:::" << m.second << std::endl;
		totalValue += m.second;
	}

	return totalValue;
}

const unsigned int Game::determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination)
{
	unsigned int winner;
	if (firstCombination > secondCombination) {
		winner = 1;
	}
	else if (secondCombination > firstCombination) {
		winner = 2;
	}
	else {
		winner = 0;
	}
	return winner;
}




void Game::configuredPlayers()
{
	this->opponentChoiseMade = Util::opponentChoiseMade;

	firstPlayer = FactoryHumanPlayer().createPlayer(Util::playerName, 1);
	firstPlayer->printPlayer();

	switch (this->opponentChoiseMade)
	{
	case 1:
		secondPlayer = FactoryAIPlayer().createPlayer(Util::aitName, 2);
		secondPlayer->printPlayer();
		break;
	case 2:
		secondPlayer = FactoryHumanPlayer().createPlayer(Util::opponetName, 2);
		secondPlayer->printPlayer();
		break;
	default:
		break;
	}

}

