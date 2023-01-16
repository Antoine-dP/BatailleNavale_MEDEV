#pragma once
#include "Grille.h"

class IA
{
private:
	Grille grilleIA;


public:
	IA();
	IA(int longueur, int largeur);
	~IA();
	void placerBateaux();
	bool tirer(Grille grilleJoueur);

	Grille getGrille() { return grilleIA; }

};
