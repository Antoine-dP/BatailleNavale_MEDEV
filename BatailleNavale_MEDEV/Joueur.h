#pragma once
#include "Grille.h"

class Joueur
{
private:
	Grille grilleJ;


public:
	Joueur();
	Joueur(int longueur, int largeur);
	~Joueur();
	void placerBateaux();
	bool tirer(Grille grilleIA);
	void afficheAll(Grille grilleIA);

	Grille getGrille() { return grilleJ; }

};


