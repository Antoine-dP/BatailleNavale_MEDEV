#include "AI.h"

AI::AI(int _difficulte) {
	difficulte = _difficulte;
	essai = NULL;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Position pos;
			pos.x = i;
			pos.y = j;
			dispo.push_back(pos);
		}
	}
}


Position AI::jouer() {
	//TODO (non fini)

	// IA nulle : random position
	if (difficulte == 0) {
		// G�n�re un nombre al�atoire entre 0 et la taille du tableau dispo
		int index = rand() % dispo.size();

		// Enregistre l'�l�ment � enlever dans la variable de r�sultat
		Position posChoisie = dispo[index];

		// Enl�ve l'�l�ment de dispo
		dispo.erase(dispo.begin() + index);
		essai.push_back(dispo[index]);

		return posChoisie;
	}

	//CODE A RETIRER EN BAS
	Position pos;
	pos.x = 0;
	pos.y = 0;
	return pos;
}