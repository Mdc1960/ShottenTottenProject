#include "Espion.h"


void Espion::applyEffet()
{
	setNumero((unsigned int) 7);
	int col;
	cout << "choississez un numero de couleur: (0:RED, 1:GREEN, 2:BLEU, 3:YELLOW, 4:ORANGE, 5:PURPLE) :" << endl;
	cin >> col;
	while (col < 0 || col > 5) {
		cout << "couleur invalide ressayez en respectant les numero :" << endl;
		cin >> col;
	}
	setColor(static_cast<Color>(col));

	cout << "Effet appliquer: espion  7 "<< col << endl;
}
