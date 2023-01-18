#include "Partie.h"

Partie::Partie()
{
}

Partie::Partie(Joueur j, IA i)
{
	_joueur = j;
	_ia = i;
}

Partie::~Partie()
{
}

void Partie::initialisationPartie() {
	Grille grilleJoueur;
	Grille grilleIA;

	// On va placer les bateaux
	int tailleBateau;
	bool bateauPlace;
	int numBateau = 0;

	// on donne la bonne taille au bateau
	if (numBateau < 3) {
		tailleBateau = numBateau + 1;
	}
	else {
		tailleBateau = numBateau;
	}

	// on pose le bateau sur la grille
	bateauPlace = false;
	if (!bateauPlace) {
		cout << "Bateau pas encore placé\n";
	}
	else {
		
	}
}


bool Partie::partieFinie() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (_joueur.getGrille().getCase(i, j) == 1 || _ia.getGrille().getCase(i, j) == 1) {
				return false;
			}
		}
	}
	return true;
}