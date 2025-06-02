#include "PorteBouclier.h"

void PorteBouclier::applyEffet()
{
	unsigned int v;
	cout << "entrer une valeur de la carte entre 1 et 3 :" << endl;
	cin >> v;
	while (v < 1 || v>3) {
		cout << "entrer une valeur valide entre 1 et 3 :" << endl;
		cin >> v;
	}
	setNumero(v);
	int col;
	cout << "choississez un numero de couleur: (0:RED, 1:GREEN, 2:BLEU, 3:YELLOW, 4:ORANGE, 5:PURPLE) :" << endl;
	cin >> col;
	while (col < 0 || col > 5) {
		cout << "couleur invalide ressayez en respectant les numero :" << endl;
		cin >> col;
	}
	setColor(static_cast<Color>(col));

	cout << "Effet appliquer: Porte-Bouclier " << v << " " << col << endl;
}
