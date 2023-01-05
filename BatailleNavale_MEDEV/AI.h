#pragma once
#include "Position.h"
#include "Joueur.h"

class AI : public Joueur {
private:
	int difficulte;
public:
	Position jouer();
};