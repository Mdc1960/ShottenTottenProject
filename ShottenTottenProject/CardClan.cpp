#include "CardClan.h"
#include "GameUtil.h"
#include <iostream>
#include <string>


CardClan::CardClan(unsigned int num, Color col)
{
	numero = num;
	color = col;
}

string CardClan::getColorString() const
{
    return Util::transformeColorToString(color);
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

std::string CardClan::getCardColor()
{
    return Util::transformeColorToString(this->color);
}

unsigned int CardClan::getCardNumber()
{
    return numero;
}


