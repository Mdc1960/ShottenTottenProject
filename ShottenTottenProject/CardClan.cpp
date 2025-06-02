#include "CardClan.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>

unsigned int CardClan::counter = 0;

void CardClan::printCard()
{
	std::cout << "$ Name : " << name << std::endl;
=======
=======
>>>>>>> f41ce8a236fb91c314268b2cc2395a10a3242fe8

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
<<<<<<< HEAD
>>>>>>> f41ce8a236fb91c314268b2cc2395a10a3242fe8
=======
>>>>>>> f41ce8a236fb91c314268b2cc2395a10a3242fe8
}
