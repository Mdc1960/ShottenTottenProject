#include "Joker.h"

void Joker::printCard()
{
	if (this->getCardNumber() > 0) {
		std::cout << "  JR:" << this->getCardNumber() << "_" << " " << getCardColor() << "  ";
	}
	else {
		std::cout << "  " << "X" << "_" << "nocard" << "  ";
	}
}

void Joker::applyEffet()
{
	unsigned int v;
	cout << "entrer une valeur de la carte entre 1 et 9 :"<<endl;
	cin >> v;
	while (v < 1 || v>9) {
		cout << "entrer une valeur valide entre 1 et 9 :"<<endl;
		cin >> v;
	}
	setNumero(v);
	int col;
	cout << "choississez un numero de couleur: (0:BROWN , 1: RED , 2:GREEN , 3: BLEU , 4:YELLOW, 5:PURPLE) :" << endl;
	cin >> col;
	while (col < 0 || col > 5) {
		cout << "couleur invalide ressayez en respectant les numero :" << endl;
		cin >> col;
	}
	setColor(static_cast<Color>(col));

	cout << "Effet appliquer: joker " << endl;
}
