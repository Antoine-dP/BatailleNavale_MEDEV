#pragma once
#include "Grille.h"

class IA
{
private:
	Grille grilleIA;


public:
	IA(int longueur, int largeur);
	~IA();
	void placerBateaux();
	bool tirer(Grille grilleJoueur);

};
