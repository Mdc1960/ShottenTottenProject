#include "Espion.h"


void Espion::printCard()
{
	if (this->getCardNumber() > 0) {
		std::cout << "  EN:" << this->getCardNumber() << "_" << " " << getCardColor() << "  ";
	}
	else {
		std::cout << "  " << "X" << "_" << "nocard" << "  ";
	}
}

void Espion::applyEffet(unique_ptr<Border>& border)
{
	setNumero((unsigned int)7);
	int col;
	cout << "choississez un numero de couleur: (0:BROWN , 1: RED , 2:GREEN , 3: BLEU , 4:YELLOW, 5:PURPLE) :" << endl;
	cin >> col;
	while (col < 0 || col > 5) {
		cout << "couleur invalide ressayez en respectant les numero :" << endl;
		cin >> col;
	}
	setColor(static_cast<Color>(col));

	cout << "Effet appliquer: espion " << endl;
}