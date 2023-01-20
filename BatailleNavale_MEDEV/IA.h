#pragma once
#include "Grille.h"

class IA
{
protected:
	Grille grilleIA;


public:
	IA();
	IA(int longueur, int largeur);
	~IA();
	//void placerBateaux();
	bool initialiser();
	bool tirer(Grille grilleJoueur);
	void afficheAll();

	Grille getGrille() { return grilleIA; }

};
