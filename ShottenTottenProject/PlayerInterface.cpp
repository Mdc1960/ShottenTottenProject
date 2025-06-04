#include "PlayerInterface.h"
#include <iostream>


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

void PlayerInterface::setPlayerName(const std::string& name) {
    playerName = name;
}

void PlayerInterface::setIdPlayer(unsigned int id) {
    idPlayer = id;
}

void PlayerInterface::ShowHand() {
    std::cout << "Hand of player " << playerName << ":" << std::endl;
    hand.printCardSet();
}
