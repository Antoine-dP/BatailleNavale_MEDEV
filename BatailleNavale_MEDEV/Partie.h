#pragma once

#include "Case.h"
#include "Grille.h"
#include "Position.h"
#include "AI.h"
#include "Joueur.h"
#include "GlobalVars.h"


class Partie {
protected:
	Grille grille1;
	Grille grille2;
	Joueur joueur1;
	Joueur joueur2;
public:
	Partie(int aiDifficulty) ;
	void SetupGrilleIA();
	void SetupGrilleJoueur();
	bool JouerTour(bool);
	void LancerPartie();
	int Set_aiDifficulty();
};