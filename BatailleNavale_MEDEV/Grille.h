#pragma once

#include <iostream>
#include <vector>

#include "Position.h"
#include "Case.h"
#include "Joueur.h"
#include "GlobalVars.h"

using namespace std;


class Grille {
	vector<Case*> caseVect;
	Joueur owner;
public:
	Grille(Joueur joueur) { owner = joueur; };
	Grille() {};
	void afficheAll();
	void afficheGrille();
	void dessineLigne(double largeur, double hauteur, int x, int y);
};