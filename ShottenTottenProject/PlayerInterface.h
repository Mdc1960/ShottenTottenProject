#pragma once
#ifndef PLAYER_INTERFACE_H
#define PLAYER_INTERFACE_H

#include <string>
#include "Hand.h"
#include "Bord.h"


static const unsigned int MAX_CARD_NUMBER_IN_PLAYER_HAND = 6;

static const unsigned int ALLOW_NUBER_PLAY_BORDER = 9;
static const unsigned int ALLOW_NUBER_CARD_COLOR = 6;


class PlayerInterface {
protected:
    std::string playerName;
    Hand hand;
    unsigned int idPlayer;

    unsigned int chooseBorderIndex = 0;
    unsigned int chooseCardIndex = 0;

    unsigned int revendicateBorderIndex = 0;

    bool isColorChooseValid = false;
    bool isBorderChooseValid = false;

    bool isRevendicateBorderValid = false;
    bool isPlayerWantToRevendicate = false;



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
    const unsigned int getRevendicateBorderIndex() const;
    const bool getIsPlayerWantToRevendicateValue() const;

    // Setters
    void setPlayerName(const std::string& name);
    void setIdPlayer(unsigned int id);
    void printPlayer();

    void setChooseBorderIndex(unsigned int& borderIndex);
    void setChooseCardIndex(unsigned int& cardIndex);
    void setRevendicateBorderIndex(unsigned int& borderIndex);

    void setIsChooseColorValid(bool&& b);
    void setIsChooseBoredValid(bool&& b);
    void setIsRevendicateBorderValid(bool&& b);
    void setIsPlayerWantToRevendicate(bool&& b);

    void fillPlayerHandWithClanCardFronBordClanStack(Bord& bord);
    std::unique_ptr<CardInterface> popCardFromPlayerHandByIndex(unsigned int& index);
    void pickCardFromBordStacksAndAddInPlayerHand(Bord& bord);
    void play(Bord& bord);

    // Virtual methods
    
    virtual void chooseBorne() = 0;
    virtual void claim(Bord& bord) = 0;
    virtual void showHand();
    virtual void chooseCard() = 0;
    
};

#endif // PLAYER_INTERFACE_H


