#pragma once
#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <string>
#include "Hand.h"

class PlayerInterface {
protected:
    std::string playerName;
    Hand hand;
    unsigned int idPlayer;

public:
    PlayerInterface();
    PlayerInterface(const std::string& name, unsigned int id);
    virtual ~PlayerInterface() = default;

    // Getters
    std::string getPlayerName() const;
    unsigned int getIdPlayer() const;
    Hand& getHand();

    // Setters
    void setPlayerName(const std::string& name);
    void setIdPlayer(unsigned int id);

    // Virtual methods
    virtual void Pick() = 0;
    virtual void ChooseBorne() = 0;
    virtual void Claim() = 0;
    virtual void ShowHand();
    virtual void ChooseCard() = 0;
};

#endif // PLAYERINTERFACE_H


