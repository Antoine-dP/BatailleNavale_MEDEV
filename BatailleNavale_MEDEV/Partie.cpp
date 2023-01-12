
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
	cout << "Vous allez poser vos bateaux\n"
		 << "Instructions :\n"
		 << "Choisir la position (x,y) en haut et gauche de votre bateau\n"
		 << "Choisir l'orientation du bateau (0 pour horizontal, 1 pour vetical\n\n";

	// ContreTorpilleur
	// /!\/!\/!\ Pour l'instant aucune vérification de disponibilité des cases n'est faite 

	Position posCT;
	bool isVertical;
	cout << "Premier bateu : Contre torpilleur (size 3)";
	cout << "\nChoix orientation ";
	cin >> isVertical;
	// Vérification de la possibilité de poser le bateau
	if (isVertical) {
		cout << "\nChoix position en x : ";
		cin >> posCT.x;
		while (posCT.x >= 10 && posCT.x < 0) {
			cout << "\nPosition invalide, reessayez : ";
			cin >> posCT.x;
		}
		cout << "\nChoix position en y : ";
		cin >> posCT.y;
		while (posCT.y >= 7 && posCT.x < 0) {
			cout << "\nPosition invalide, ressayez : ";
			cin >> posCT.y;
		}
	}

	//ContreTorpilleur(posCT, isVertical);
	;
}

void Partie::JouerTour() {
	;
}

void Partie::LancerPartie() {
	;
}



