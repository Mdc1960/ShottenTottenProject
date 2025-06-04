#include "CardClan.h"
#include <iostream>
#include <string>


CardClan::CardClan(unsigned int num, Color col)
{
	numero = num;
	color = col;
}

string CardClan::getColorString() const
{
    switch (color) {
        case Color::RED: return "Red";
        case Color::BLEU: return "Bleu";
        case Color::GREEN: return "Green";
        case Color::YELLOW: return "Yellow";
        case Color::PURPLE: return "Purple";
        case Color::ORANGE: return "Orange";
        default: return "Inconnu";
    }
}

string CardClan::getNamecard()
{
    return "Cardclan " + getColorString() + " " + to_string(numero);

}



void CardClan::printCard()
{
    std::cout << "   " << numero << "_" << getColorString() << "   ";
}

