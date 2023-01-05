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

	}

	//CODE A RETIRER EN BAS
	Position pos;
	pos.x = 0;
	pos.y = 0;
	return pos;
}