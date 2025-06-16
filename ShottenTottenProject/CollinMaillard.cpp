#include "CollinMaillard.h"

unsigned int CollinMaillard::calculerScore(unsigned int numero)
{
	vector<unsigned int> Cardside = numero == 1 ? innerBorder->getFirstPlayerSideAllCardNumber() 
		: innerBorder->getSecondPlayerSideAllCardNumber();
    int somme = 0;
    for (auto& cardnumber : Cardside) {   
            somme += cardnumber;
    }
    return somme;
}

unsigned int CollinMaillard::claim()
{
    unsigned int score1 = calculerScore((unsigned int)1);
    unsigned int score2 = calculerScore((unsigned int)2);
	if (score1 > score2) {
		return 1;
	}
	else if (score2 > score1) {
		return 2;
	}
	else {
		return 0; // Égalité
	}
}