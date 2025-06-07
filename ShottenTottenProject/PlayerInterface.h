#pragma once
#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <string>
#include "Hand.h"
#include "Bord.h"


static const unsigned int MAX_CARD_NUMBER_IN_PLAYER_HAND = 6;


class PlayerInterface {
protected:
    std::string playerName;
    Hand hand;
    unsigned int idPlayer;

    unsigned int chooseBorderIndex = 0;
    unsigned int chooseCardIndex = 0;

    bool isColorChooseValid = false;
    bool isBorderChooseValid = false;

    void pushCardInPlayerHand(std::unique_ptr<CardInterface> card);

public:
    PlayerInterface();
    PlayerInterface(const std::string& name, unsigned int id);
    virtual ~PlayerInterface() = default;

    // Getters
    std::string getPlayerName() const;
    unsigned int getIdPlayer() const;
    Hand& getHand();

    const unsigned int getChooseBorderIndex() const;
    const unsigned int getChooseCardIndex() const;

    // Setters
    void setPlayerName(const std::string& name);
    void setIdPlayer(unsigned int id);
    void printPlayer();

    void setChooseBorderIndex(unsigned int& borderIndex);
    void setChooseCardIndex(unsigned int& cardIndex);

    void setIsChooseColorValid(bool&& b);
    void setIsChooseBoredValid(bool&& b);

    void fillPlayerHandWithClanCardFronBordClanStack(Bord& bord);
    std::unique_ptr<CardInterface> popCardFromPlayerHandByIndex(unsigned int& index);
    void pickCardFromBordStacksAndAddInPlayerHand(Bord& bord);
    void play(Bord& bord);

    // Virtual methods
    
    virtual void chooseBorne() = 0;
    virtual void claim(Bord& bord) = 0;
    virtual void showHand();
    virtual void chooseCard() = 0;
    //virtual void putCardInGameBordBorder(Bord& bord, std::unique_ptr<CardInterface> card, const unsigned int& chooseBorderIndex) = 0;
    
};

#endif // PLAYERINTERFACE_H


