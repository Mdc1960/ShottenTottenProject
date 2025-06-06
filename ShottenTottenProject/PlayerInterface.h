#pragma once
#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <string>
#include "Hand.h"
#include "Bord.h"
#include "RevendicateBorder.h"
#include "PlayerPlay.h"

class PlayerInterface {
protected:
    std::string playerName;
    Hand hand;
    unsigned int idPlayer;

    unsigned int chooseBorderIndex;
    unsigned int chooseCardIndex;

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
    void pickCardFromBordStacks(Bord& bord);
    virtual void chooseBorne() = 0;
    virtual void claim(Bord& bord) = 0;
    virtual void showHand();
    virtual void chooseCard() = 0;
    virtual void fillPlayerHandWithClanCardFronBordClanStack(Bord& bord) = 0;
    virtual std::unique_ptr<CardInterface> popCardFromPlayerHandByIndex(unsigned int& index) = 0;
    virtual void putCardInGameBordBorder(Bord& bord, std::unique_ptr<CardInterface> card, const unsigned int& chooseBorderIndex) = 0;
    void play(Bord& bord);
};

#endif // PLAYERINTERFACE_H


