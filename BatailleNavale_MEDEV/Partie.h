#pragma once

#include "Case.h"
#include "Grille.h"
#include "Position.h"
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
	void JouerTour();
	void LancerPartie();
};