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
    unsigned int getNumero() { return numero; }
    string getColorString() const;
    string getNamecard() override;
    void printCard() override;
        
};
