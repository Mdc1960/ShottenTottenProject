#include "PlayerInterface.h"
#include <iostream>


void PlayerInterface::pushCardInPlayerHand(std::unique_ptr<CardInterface> card)
{
    hand.pushBackCard(std::move(card));
}

PlayerInterface::PlayerInterface() : playerName(""), idPlayer(0) {}

PlayerInterface::PlayerInterface(const std::string& name, unsigned int id)
    : playerName(name), idPlayer(id) {
}

std::string PlayerInterface::getPlayerName() const {
    return playerName;
}

unsigned int PlayerInterface::getIdPlayer() const {
    return idPlayer;
}

Hand& PlayerInterface::getHand() {
    return hand;
}

const unsigned int PlayerInterface::getChooseBorderIndex() const
{
    return this->chooseBorderIndex;
}

const unsigned int PlayerInterface::getChooseCardIndex() const
{
    return this->chooseCardIndex;
}

void PlayerInterface::setChooseBorderIndex(unsigned int& borderIndex)
{
    this->chooseBorderIndex = borderIndex;
}

void PlayerInterface::setChooseCardIndex(unsigned int& cardIndex)
{
    this->chooseCardIndex = cardIndex;
}

void PlayerInterface::setIsChooseColorValid(bool&& b)
{
    this->isColorChooseValid = b;
}

void PlayerInterface::setIsChooseBoredValid(bool&& b)
{
    this->isBorderChooseValid = b;
}

void PlayerInterface::setPlayerName(const std::string& name) {
    playerName = name;
}

void PlayerInterface::setIdPlayer(unsigned int id) {
    idPlayer = id;
}

void PlayerInterface::printPlayer()
{
    std::cout << "#" << idPlayer << " " << playerName << std::endl;
}

void PlayerInterface::pickCardFromBordStacksAndAddInPlayerHand(Bord& bord)
{
    pushCardInPlayerHand(std::move(bord.popAndGetCardFromClanStack()));
}

void PlayerInterface::showHand() {
    std::cout << "Hand of player " << playerName << ":\n" << std::endl;
    hand.printCardSet();
}

void PlayerInterface::fillPlayerHandWithClanCardFronBordClanStack(Bord& bord)
{
    for (unsigned int index = 0; index < MAX_CARD_NUMBER_IN_PLAYER_HAND; ++index) {
        pickCardFromBordStacksAndAddInPlayerHand(bord);
    }
}

std::unique_ptr<CardInterface> PlayerInterface::popCardFromPlayerHandByIndex(unsigned int& index)
{
    unsigned int indexPos = index;
    return hand.popAndGetCardByIndex(std::move(indexPos));
}

void PlayerInterface::play(Bord& bord)
{
    
    chooseCard();
    chooseBorne();
    /*putCardInGameBordBorder(bord, popCardFromPlayerHandByIndex(chooseCardIndex), chooseBorderIndex);
    pickCardFromBordStacksAndAddInPlayerHand(bord);*/
}
