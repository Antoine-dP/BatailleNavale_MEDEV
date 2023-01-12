#pragma once
#include "Grille.h"

class Joueur
{
private:
	Grille grilleJ;


public:
	Joueur(int longueur, int largeur);
	~Joueur();
	void placerBateaux();
	bool tirer(Grille grilleIA);

};


