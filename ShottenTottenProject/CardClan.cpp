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
        case Color::RED: return "RD";
        case Color::BLUE: return "BE";
        case Color::GREEN: return "GN";
        case Color::BROWN: return "BN";
        case Color::PURPLE: return "PE";
        case Color::YELLOW: return "YW";
        default: return "Inconnu";
    }
}

string CardClan::getNamecard()
{
    return "Cardclan " + getColorString() + " " + to_string(numero);

}



void CardClan::printCard()
{
    if (numero > 0) {
        std::cout << "  CL:" << numero << "_" << " " << getColorString() << "  ";
    }
    else {
        std::cout << "  " << "X" << "_" << "nocard" << "  ";
    }
    
}


