#pragma once
#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <string>
#include "Hand.h"
#include "Bord.h"

class PlayerInterface {
protected:
    std::string playerName;
    Hand hand;
    unsigned int idPlayer;

    virtual void pushCardInPlayerHand(std::unique_ptr<CardInterface> card) = 0;

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
    virtual void pickCardFromBordStacks(Bord& bord) = 0;
    virtual void ChooseBorne() = 0;
    virtual void Claim() = 0;
    virtual void ShowHand();
    virtual void ChooseCard() = 0;
    virtual void fillPlayerHandWithClanCardFronBordClanStack(Bord& bord) = 0;
    virtual std::unique_ptr<CardInterface> popCardFromPlayerHandByIndex(unsigned int&& index) = 0;
};

#endif // PLAYERINTERFACE_H


