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
	bool nonfinie = true;
public:
	Grille(Joueur joueur) { owner = joueur; };
	Grille() {};
	void afficheAll();
	void afficheGrille();
	bool getNonfinie() { return nonfinie; };
	void dessineLigne(double largeur, double hauteur, int x, int y);
	bool jouable(Position) { return false; }; //Une position est-elle jouable ?
	bool jouerGrille(Position) { return false; }; //ajoute le tire dans les cases de la grille et renvoie si touché ou plouf
};