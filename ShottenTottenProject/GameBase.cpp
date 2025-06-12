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

		unsigned int firstBorderSide;
		unsigned int secondBorderSide;

		unsigned int firstPlayerRevendicateBorderIndex;
		bool isFirstPlayerWantToRevendicate;
		
		unsigned int aiPlayerRevendicateBorderIndex;
		bool isAIPlayerWantToRevendicate;

		std::unique_ptr<CardInterface> aiPlayedCard;
		std::unique_ptr<CardInterface> playerPlayedCard;

		switch (turn) {

		case 0:
			//FIRST PLAYER PLAY.

			playPhase->acceptPlayer(firstPlayer.get());

			indexCard = firstPlayer->getChooseCardIndex();
			indexBorder = firstPlayer->getChooseBorderIndex();

			firstBorderSide = gameBord.getBorderSidePutCardIndex(std::move(indexBorder - 1), std::move(1));

		/*#ifdef _WIN32
			std::system("cls");
		#else
			std::system("clear");
		#endif*/



			if (firstBorderSide < 3) {

				try {

					playerPlayedCard = std::move(firstPlayer->popCardFromPlayerHandByIndex(indexCard));

					if (playerPlayedCard != nullptr) {

						gameBord.putCardInBorderByPlayerIdAndColumnIndex(std::move(playerPlayedCard), std::move(1), std::move(indexBorder - 1));

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

								playerCombinationMap = fillPlayerRevendicateMap(firstPlayerRevendicateBorderIndex, std::move(1));

								switch (this->opponentChoiseMade) {
								case 1:
									aiCombinationMap = fillPlayerRevendicateMap(firstPlayerRevendicateBorderIndex,std::move(2));

									setPlayerCombination(getRevendicateBorderTotalValueFromMap(playerCombinationMap));
									setAICombination(getRevendicateBorderTotalValueFromMap(aiCombinationMap));

									std::cout << "COMBINE 1 : " << playerCombination << std::endl;
									std::cout << "COMBINE 2 : " << aiCombination << std::endl;

									winner = determineBorderWinnerByCombination(playerCombination, aiCombination);

									std::cout << "The Winner : " << winner << std::endl;

									switch (winner) {
									case 0 :
										std::cout << "\aPlayer '" << firstPlayer->getPlayerName() << "' you win the border " << firstPlayerRevendicateBorderIndex << std::endl;
										firstPlayerRevendicateBorderList.push_back(firstPlayerRevendicateBorderIndex);
										break;
									case 1:
										break;
									case 2:
										break;
									default:
										break;
									}

									break;
								case 2:
									opponentCombinationMap = fillPlayerRevendicateMap(firstPlayerRevendicateBorderIndex, std::move(2));
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
					std::cout << "Error : " << exp.what() << std::endl;
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

				if (secondBorderSide < 3) {

					try {

						aiPlayedCard = std::move(secondPlayer->popCardFromPlayerHandByIndex(aiIndexCard));

						if (aiPlayedCard != nullptr) {
							gameBord.putCardInBorderByPlayerIdAndColumnIndex(std::move(aiPlayedCard), std::move(2), std::move(aiIndexBorder + 0));

							turn = (turn + 1) % 2;

							if (!gameBord.getIsClanStackEmpty()) {
								secondPlayer->pickCardFromBordStacksAndAddInPlayerHand(gameBord);
							}

							if (Bord::numberOfCardPutInBorders >= 12) {
								notify();
								revendicatePhase->acceptPlayer(secondPlayer.get());

								isAIPlayerWantToRevendicate = secondPlayer->getIsPlayerWantToRevendicateValue();

								if (isAIPlayerWantToRevendicate) {
									aiPlayerRevendicateBorderIndex = secondPlayer->getRevendicateBorderIndex();

									std::cout << "AI Player want to revendicate : " << aiPlayerRevendicateBorderIndex << std::endl;

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

}