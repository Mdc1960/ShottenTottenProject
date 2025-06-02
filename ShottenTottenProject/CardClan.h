#pragma once

#include "CardInterface.h"
#include "Color.h"
#include <iostream>

/*!
* CardClan
*/
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

};
