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
	Position jouer();
};