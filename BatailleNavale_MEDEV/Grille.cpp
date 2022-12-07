
#include "Grille.h"

Grille::Grille(Joueur joueur) {
	owner = joueur;
}

void Grille::afficheAll() {
	afficheGrille();
	// Affiche les objets dans la grille
	for (int i = 0; i < caseVect.size(); i++)
	{
		(*caseVect[i]).affiche();
	}
}

void Grille::afficheGrille() {
	// Affiche la grille (les lignes verticales & horizontales)
}