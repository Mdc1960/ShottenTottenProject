#include "Game.h"


Game::Game() : gameMode(Util::gameMode)
{
	configuredPlayers();
	buildGameBord(std::move(54), std::move(10));
	add(&gameBord);
}

void Game::putCardInBordersColumnUsingPlayerId(std::unique_ptr<CardInterface> card, unsigned int&& playerId, unsigned int&& columnIndex)
{
	gameBord.putCardInBorderByPlayerIdAndColumnIndex(std::move(card), std::move(playerId), std::move(columnIndex));
	notify();
	
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
}




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

void Game::setLastPlayerSidePutCard(unsigned int borderIndex, unsigned int lastPlayerSidePutCard)
{
	gameBord.setLastPlayerSidePutCard(borderIndex, lastPlayerSidePutCard);
}

const unsigned int Game::getLastPlayerSidePutCard(unsigned int borderIndex)
{
	return gameBord.getLastPlayerSidePutCard(borderIndex);
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
		totalValue += m.second;
	}

	return totalValue;
}

const unsigned int Game::determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination)
{
	unsigned int winner;
	if (firstCombination > secondCombination && firstCombination >= 11) {
		winner = 1;
	}
	else if (secondCombination > firstCombination && secondCombination >= 11) {
		winner = 2;
	}
	else {
		winner = 0;
	}
	return winner;
}

bool Game::isPlayerWinTheGame(std::vector<unsigned int> listRevendicateBorder)
{
	if (listRevendicateBorder.size() >= 3) {

		std::sort(listRevendicateBorder.begin(), listRevendicateBorder.end());

		for (unsigned int index = 0; index <= listRevendicateBorder.size() - 3; index++) {

			if ((listRevendicateBorder[index + 1] == listRevendicateBorder[index] + 1) && (listRevendicateBorder[index + 2] == listRevendicateBorder[index + 1] + 1)) {
				return true;
			}
			
		}
		
		
	}
	
	return listRevendicateBorder.size() >= 5 ? true : false;
}

bool Game::findValueInList(std::vector<unsigned int> list, unsigned int value)
{
	return std::find(list.begin(), list.end(), value) != list.end();
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

