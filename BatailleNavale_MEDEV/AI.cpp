#include "AI.h"
#include <random>

Position AI::jouer() {
	//TODO (non fini)

	// IA nulle : random position
	if (difficulte == 0) {
		// G�n�re un nombre al�atoire entre 0 et la taille du tableau
		int index = rand() % dispo.size();

		// Enregistre l'�l�ment � enlever dans la variable de r�sultat
		Position posChoisie = dispo[index];

		// Enl�ve l'�l�ment du tableau
		dispo.erase(dispo.begin() + index);

		return posChoisie;
	}

	//CODE A RETIRER EN BAS
	Position pos;
	pos.x = 0;
	pos.y = 0;
	return pos;
}