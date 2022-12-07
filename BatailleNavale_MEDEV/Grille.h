#pragma once

#include <iostream>
#include <vector>

#include "Position.h"
#include "Case.h"
#include "Joueur.h"

using namespace std;


class Grille {
	vector<Case*> caseVect;
	Joueur owner;
public:
	Grille(Joueur joueur) { owner = joueur; };
	void afficheAll();
	void afficheGrille();
};