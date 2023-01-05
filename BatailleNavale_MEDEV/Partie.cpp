
#include "Partie.h"

Partie::Partie(int aiDifficulty) {
	joueur1 = Joueur();
	joueur2 = Joueur();
	grille1 = Grille(joueur1);
	grille2 = Grille(joueur2);
}

void Partie::SetupGrilleIA() {
	;
}

void Partie::SetupGrilleJoueur() {
	//TODO (a finir/refaire)
	// Poser les bateaux
	cout << "Vous allez poser vos bateaux\n";
	// ContreTorpilleur
	Position posCT;
	cout << "Contre torpilleur (size 3)\n" << "Choix position en x : ";
	cin >> posCT.x;
	cout << "\nChoix position en y : ";
	cin >> posCT.y;
	cout << "\nChoix orientation ";

	;
}

void Partie::JouerTour() {
	;
}

void Partie::LancerPartie() {
	;
}



