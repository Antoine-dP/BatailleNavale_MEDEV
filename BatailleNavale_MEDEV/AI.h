#pragma once
#include "Position.h"
#include "Joueur.h"
#include <vector>

using namespace std;

class AI : public Joueur {
private:
	int difficulte;
	vector<Position> dispo;
public:
	AI() { difficulte = 0; };
	AI(int n) { difficulte = n; };
	Position jouer();
};