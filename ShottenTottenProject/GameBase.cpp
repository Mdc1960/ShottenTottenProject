#include "GameBase.h"

GameBase::GameBase() :
	Game()
{
	this->gameMode = Util::gameMode;
}

void GameBase::startGame()
{

	playPhase = std::make_shared<PlayerPlay>();

	revendicatePhase = std::make_shared<RevendicateBorder>();

	fillPlayerHandWithInitialCardsUsingId(std::move(1));
	fillPlayerHandWithInitialCardsUsingId(std::move(2));

	std::unordered_map<std::string, unsigned int> playerCombinationMap;
	std::unordered_map<std::string, unsigned int> opponentCombinationMap;
	std::unordered_map<std::string, unsigned int> aiCombinationMap;

	unsigned int winner;

	turn = 0;

	while (!isGameOver) {

		notify();

		unsigned int indexCard;
		unsigned int indexBorder;

		unsigned int aiIndexCard;
		unsigned int aiIndexBorder;
		
		unsigned int opponentIndexCard;
		unsigned int opponentIndexBorder;

		unsigned int firstBorderSide;
		unsigned int secondBorderSide;

		unsigned int firstPlayerRevendicateBorderIndex;
		bool isFirstPlayerWantToRevendicate;
		
		unsigned int aiPlayerRevendicateBorderIndex;
		bool isAIPlayerWantToRevendicate;
		
		unsigned int opponentPlayerRevendicateBorderIndex;
		bool isOpponentPlayerWantToRevendicate;

		unsigned int borderCapacity;

		std::unique_ptr<CardInterface> aiPlayedCard;
		std::unique_ptr<CardInterface> playerPlayedCard;
		std::unique_ptr<CardInterface> opponentPlayerPlayedCard;

		switch (turn) {

		case 0:
			//FIRST PLAYER PLAY.

			playPhase->acceptPlayer(firstPlayer.get());

			indexCard = firstPlayer->getChooseCardIndex();
			indexBorder = firstPlayer->getChooseBorderIndex();

			firstBorderSide = gameBord.getBorderSidePutCardIndex(std::move(indexBorder - 1), std::move(1));

			borderCapacity = gameBord.getBorderCapacityByIndex(indexBorder - 1);

		/*#ifdef _WIN32
			std::system("cls");
		#else
			std::system("clear");
		#endif*/


			//Get BorderCapacity.
			if (firstBorderSide < borderCapacity) {

				try {

					playerPlayedCard = std::move(firstPlayer->popCardFromPlayerHandByIndex(indexCard));

					if (playerPlayedCard != nullptr) {

						putCardInBordersColumnUsingPlayerId(std::move(playerPlayedCard), std::move(1), std::move(indexBorder - 1));

						turn = (turn + 1) % 2;

						if (!gameBord.getIsClanStackEmpty()) {
							firstPlayer->pickCardFromBordStacksAndAddInPlayerHand(gameBord);
						}

						if (Bord::numberOfCardPutInBorders >= 4) {
							notify();
							revendicatePhase->acceptPlayer(firstPlayer.get());
							isFirstPlayerWantToRevendicate = firstPlayer->getIsPlayerWantToRevendicateValue();

							if (isFirstPlayerWantToRevendicate) {
								firstPlayerRevendicateBorderIndex = firstPlayer->getRevendicateBorderIndex() - 1;

								std::cout << "First Player want to revendicate : " << firstPlayerRevendicateBorderIndex + 1 << std::endl;

								

								switch (this->opponentChoiseMade) {
								case 1:

									winner = gameBord.claim(firstPlayerRevendicateBorderIndex);

									std::cout << "The Winner Of The Border : " << winner << std::endl;

									switch (winner) {
									case 0:
										//TODO : Equality.

										break;
									case 1:
										std::cout << "\aPlayer '" << firstPlayer->getPlayerName() << "' you win the border " << firstPlayerRevendicateBorderIndex + 1 << std::endl;
										firstPlayerRevendicateBorderList.push_back(firstPlayerRevendicateBorderIndex);
										//TODO : Determine the WINNER of the game.
										break;
									case 2:
										//Second Player Win the border(AI).
										std::cout << "\aPlayer '" << secondPlayer->getPlayerName() << "' you win the border " << firstPlayerRevendicateBorderIndex + 1 << std::endl;
										aiPlayerRevendicateBorderList.push_back(firstPlayerRevendicateBorderIndex);
										break;
									case 3:
										std::cout << "No winner for the border " << firstPlayerRevendicateBorderIndex + 1 << "." << std::endl;
										break;
									default:
										break;
									}

									break;
								case 2:
									

									winner = gameBord.claim(firstPlayerRevendicateBorderIndex);

									std::cout << "The Winner : " << winner << std::endl;

									switch (winner) {
									case 0:
										//TODO : Equality.
										break;
									case 1:
										std::cout << "\aPlayer '" << firstPlayer->getPlayerName() << "' you win the border " << firstPlayerRevendicateBorderIndex + 1 << std::endl;
										firstPlayerRevendicateBorderList.push_back(firstPlayerRevendicateBorderIndex);
										break;
									case 2:
										//Second Player Win the border(AI).
										std::cout << "\aPlayer '" << secondPlayer->getPlayerName() << "' you win the border " << firstPlayerRevendicateBorderIndex + 1 << std::endl;
										opponentPlayerRevendicateBorderList.push_back(firstPlayerRevendicateBorderIndex);
										break;
									case 3:
										std::cout << "No winner for the border " << firstPlayerRevendicateBorderIndex + 1 << "." << std::endl;
										break;
									default:
										break;
									}

									break;
								default:
									break;
								}

								//std::this_thread::sleep_for(std::chrono::seconds(2));
								
							}
							firstPlayer->setIsRevendicateBorderValid(false);
						}

					}

				}
				catch (GameException exp) {
					std::cout << "\aError : " << exp.what() << std::endl;
				}

			}
			else {
				std::cout << "\aPlayer '" << firstPlayer->getPlayerName() << "' the border side " << indexBorder << " is full.You cannot put card in this border side." << std::endl;
			}

			firstPlayer->setIsChooseColorValid(false);
			firstPlayer->setIsChooseBoredValid(false);




			break;
		case 1:
			//OPPONENT PLAYER PLAY (AI/HUMAN PLAYER).
			switch (opponentChoiseMade) {

			case 1:
				//AI Play

			/*#ifdef _WIN32
				std::system("cls");
			#else
				std::system("clear");
			#endif*/

				std::cout << "AI is playing" << std::endl;


				playPhase->acceptPlayer(secondPlayer.get());

				aiIndexCard = secondPlayer->getChooseCardIndex();
				aiIndexBorder = secondPlayer->getChooseBorderIndex();

				secondBorderSide = gameBord.getBorderSidePutCardIndex(std::move(aiIndexBorder), std::move(2));
				borderCapacity = gameBord.getBorderCapacityByIndex(aiIndexBorder);

				if (secondBorderSide < borderCapacity) {

					try {

						aiPlayedCard = std::move(secondPlayer->popCardFromPlayerHandByIndex(aiIndexCard));

						if (aiPlayedCard != nullptr) {
							gameBord.putCardInBorderByPlayerIdAndColumnIndex(std::move(aiPlayedCard), std::move(2), std::move(aiIndexBorder + 0));

							turn = (turn + 1) % 2;

							if (!gameBord.getIsClanStackEmpty()) {
								secondPlayer->pickCardFromBordStacksAndAddInPlayerHand(gameBord);
							}

							if (Bord::numberOfCardPutInBorders >= 4) {
								notify();
								revendicatePhase->acceptPlayer(secondPlayer.get());

								isAIPlayerWantToRevendicate = secondPlayer->getIsPlayerWantToRevendicateValue();

								if (isAIPlayerWantToRevendicate) {
									aiPlayerRevendicateBorderIndex = secondPlayer->getRevendicateBorderIndex();

									std::cout << "AI Player want to revendicate : " << aiPlayerRevendicateBorderIndex << std::endl;


									winner = gameBord.claim(aiPlayerRevendicateBorderIndex);

									std::cout << "The Winner Of The Border : " << winner << std::endl;

									switch (winner) {
									case 0:
										//TODO : Equality.
										break;
									case 1:
										std::cout << "\aPlayer '" << firstPlayer->getPlayerName() << "' you win the border " << aiPlayerRevendicateBorderIndex << std::endl;
										firstPlayerRevendicateBorderList.push_back(aiPlayerRevendicateBorderIndex);
										//TODO : Determine the WINNER of the game.
										break;
									case 2:
										//Second Player Win the border(AI).
										std::cout << "\aPlayer '" << secondPlayer->getPlayerName() << "' you win the border " << aiPlayerRevendicateBorderIndex << std::endl;
										aiPlayerRevendicateBorderList.push_back(aiPlayerRevendicateBorderIndex);
										break;
									case 3:
										std::cout << "No winner for the border " << aiPlayerRevendicateBorderIndex << "." << std::endl;
										break;
									default:
										break;
									}


									//std::this_thread::sleep_for(std::chrono::seconds(2));
								}
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
			case 2:
				//Opponent
				

				playPhase->acceptPlayer(secondPlayer.get());

				opponentIndexCard = secondPlayer->getChooseCardIndex();
				opponentIndexBorder = secondPlayer->getChooseBorderIndex();

				secondBorderSide = gameBord.getBorderSidePutCardIndex(std::move(opponentIndexBorder - 1), std::move(2));

				borderCapacity = gameBord.getBorderCapacityByIndex(opponentIndexBorder - 1);


			/*#ifdef _WIN32
				std::system("cls");
			#else
				std::system("clear");
			#endif*/


				if (secondBorderSide < borderCapacity) {

					try {

						opponentPlayerPlayedCard = std::move(secondPlayer->popCardFromPlayerHandByIndex(opponentIndexCard));

						if (opponentPlayerPlayedCard != nullptr) {

							putCardInBordersColumnUsingPlayerId(std::move(opponentPlayerPlayedCard), std::move(2), std::move(opponentIndexBorder - 1));

							turn = (turn + 1) % 2;

							if (!gameBord.getIsClanStackEmpty()) {
								secondPlayer->pickCardFromBordStacksAndAddInPlayerHand(gameBord);
							}

							if (Bord::numberOfCardPutInBorders >= 4) {

								notify();
								revendicatePhase->acceptPlayer(secondPlayer.get());
								isOpponentPlayerWantToRevendicate = secondPlayer->getIsPlayerWantToRevendicateValue();

								if (isOpponentPlayerWantToRevendicate) {

									opponentPlayerRevendicateBorderIndex = secondPlayer->getRevendicateBorderIndex() - 1;

									std::cout << "Opponent Player want to revendicate : " << opponentPlayerRevendicateBorderIndex + 1 << std::endl;

									winner = gameBord.claim(opponentPlayerRevendicateBorderIndex);

									std::cout << "The Winner Of The Border : " << winner << std::endl;

									switch (winner) {
									case 0:
										//TODO : Equality.
										break;
									case 1:
										std::cout << "\aPlayer '" << firstPlayer->getPlayerName() << "' you win the border " << opponentPlayerRevendicateBorderIndex + 1 << std::endl;
										firstPlayerRevendicateBorderList.push_back(opponentPlayerRevendicateBorderIndex);
										break;
									case 2:
										//Second Player Win the border(AI).
										std::cout << "\aPlayer '" << secondPlayer->getPlayerName() << "' you win the border " << opponentPlayerRevendicateBorderIndex + 1 << std::endl;
										opponentPlayerRevendicateBorderList.push_back(opponentPlayerRevendicateBorderIndex);
										break;
									case 3:
										std::cout << "No winner for the border " << opponentPlayerRevendicateBorderIndex << "." << std::endl;
										break;
									default:
										break;
									}

								}
								secondPlayer->setIsRevendicateBorderValid(false);

							}

						}

					}
					catch (GameException exp) {
						std::cout << "\aError : " << exp.what() << std::endl;
					}

				}
				else {
					std::cout << "\aPlayer '" << secondPlayer->getPlayerName() << "' the border side " << opponentIndexBorder << " is full.You cannot put card in this border side." << std::endl;
				}

				secondPlayer->setIsChooseColorValid(false);
				secondPlayer->setIsChooseBoredValid(false);


				break;

			default:
				break;

			}

			break;

		default:
			break;
		}

	}

}