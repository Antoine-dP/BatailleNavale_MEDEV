#pragma once
#include "Position.h"
#include "Joueur.h"
#include <vector>

class AI : public Joueur {
private:
	int difficulte;
	vector<Position> essai;
	vector<Position> dispo;
public:
	AI(int _difficulte);
	Position jouer();
};