#include "AI.h"
#include <random>

Position AI::jouer() {
	//TODO (non fini)

	// IA nulle : random position
	if (difficulte == 0) {
		// Génère un nombre aléatoire entre 0 et la taille du tableau
		int index = rand() % dispo.size();

		// Enregistre l'élément à enlever dans la variable de résultat
		Position posChoisie = dispo[index];

		// Enlève l'élément du tableau
		dispo.erase(dispo.begin() + index);

		return posChoisie;
	}

	//CODE A RETIRER EN BAS
	Position pos;
	pos.x = 0;
	pos.y = 0;
	return pos;
}