#pragma once

#include "Color.h"
#include "CardInterface.h"

class CardClan : public CardInterface
{
private:
    unsigned int numero;
    Color color;
protected:
    void setColor(Color newColor) { color = newColor; }
    void setNumero(unsigned int newNumero) { numero = newNumero; }
public:
    CardClan(unsigned int num, Color col);
    Color getColor() { return color; }
    string getNamecard() override;
    void printCard() override;

    std::string getCardColor();
    unsigned int getCardNumber();
    
        
};
