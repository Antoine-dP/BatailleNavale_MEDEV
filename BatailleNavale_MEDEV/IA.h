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
	bool tireSurIA(int posX, int posY);


	Grille getGrille() { return grilleIA; }
};
