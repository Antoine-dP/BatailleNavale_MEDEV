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