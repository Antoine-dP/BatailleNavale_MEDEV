
#include "Partie.h"

Partie::Partie(int aiDifficulty) {
	joueur1 = Joueur();
	joueur2 = AI(1);
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
	cout << "Premier bateu : Contre torpilleur (size 3)\n"
		 << "Choix position en x : ";
	cin >> posCT.x;
	cout << "\nChoix position en y : ";
	cin >> posCT.y;
	cout << "\nChoix orientation ";
	cin >> isVertical;

	//ContreTorpilleur(posCT, isVertical);
	;
}

bool Partie::JouerTour(bool jj) {
	bool etat = true;
	if (jj) {
		while (etat && grille1.getNonfinie()) {
			Position tir;
			cout << "Choix tir en x :" << endl;
			cin >> tir.x;
			cout << "Choix tir en y :" << endl;
			cin >> tir.y;
			while (grille1.jouable(tir)) {
				cout << "impossible de jouer sur cette case" << endl;
				cout << "Choix tir en x :" << endl;
				cin >> tir.x;
				cout << "Choix tir en y :" << endl;
				cin >> tir.y;
			}
			etat = grille1.jouerGrille(tir);
		}
		return grille1.getNonfinie();
	}
	else {
		while (etat && grille2.getNonfinie()) {
			etat = grille2.jouerGrille(joueur2.jouer());
		} 
		return grille2.getNonfinie();
	}
}

int Partie::Set_aiDifficulty() {
	int n = 2;
	while (n != 0 && n != 1) {
		cout << "Choix IA : 0 pour facile, 1 pour difficile" << endl;
		cin >> n;
	}
	return n;
}

void Partie::LancerPartie() {
	//Choix de la difficulte
	int diff = Set_aiDifficulty();

	//Setup des joueurs et grilles
	joueur1 = Joueur();
	grille1 = Grille(joueur1);

	joueur2 = AI(diff);
	grille2 = Grille(joueur2);

	//Remplissage des grilles
	SetupGrilleIA();
	SetupGrilleJoueur();

	//condition de victoire
	bool nonFin = true;

	//Joueur jouant
	bool jj = 0;

	//partie
	while (nonFin) {
		nonFin = JouerTour(jj);
		jj = !jj;
	}
	
	if (jj) {
		cout << "défaite)";
	} else{ cout << "victoire"; }
}




