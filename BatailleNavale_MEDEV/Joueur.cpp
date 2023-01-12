#include "Joueur.h"

using namespace std;

Joueur::Joueur(int longueur, int largeur)
{
	grilleJ = Grille(longueur, largeur);
}

Joueur::~Joueur()
{
}

void Joueur::placerBateaux() {
	int posX, posY;
	char orientation;
	bool possible = false;

	// Bateau 1 : (Porte Avion 5 cases)
	while (!possible) {
		cout << "Placement Porte Avion (5 cases) : " << endl;
		cout << "Orientation (h ou v) : ";
		cin >> orientation;
		cout << endl;
		cout << "Position en x : ";
		cin >> posX;
		cout << endl << "Position en y : ";
		cin >> posY;
		possible = grilleJ.placerBateau(5, orientation, posX, posY);
	}

	possible = false;
	// Bateau 2 : (Croiseur 4 cases)
	while (!possible) {
		cout << "Placement Croiseur (4 cases) : " << endl;
		cout << "Orientation (h ou v) : ";
		cin >> orientation;
		cout << endl;
		cout << "Position en x : ";
		cin >> posX;
		cout << endl << "Position en y : ";
		cin >> posY;
		possible = grilleJ.placerBateau(4, orientation, posX, posY);
	}

	possible = false;
	// Bateau 3 : (Sous-marin 3 cases)
	while (!possible) {
		cout << "placement Sous-Marin (3 cases) : " << endl;
		cout << "Orientation (h ou v) : ";
		cin >> orientation;
		cout << endl;
		cout << "Position en x : ";
		cin >> posX;
		cout << endl << "Position en y : ";
		cin >> posY;
		possible = grilleJ.placerBateau(3, orientation, posX, posY);
	}

	possible = false;
	// Bateau 4 : (Sous-marin 3 cases)
	while (!possible) {
		cout << "Placement Sous-Marin (3 cases) : " << endl;
		cout << "Orientation (h ou v) : ";
		cin >> orientation;
		cout << endl;
		cout << "Position en x : ";
		cin >> posX;
		cout << endl << "Position en y : ";
		cin >> posY;
		possible = grilleJ.placerBateau(3, orientation, posX, posY);
	}

	possible = false;
	// Bateau 5 : (Torpilleur 2 cases)
	while (!possible) {
		cout << "Placement Torpilleur (2 cases) : " << endl;
		cout << "Orientation (h ou v) : ";
		cin >> orientation;
		cout << endl;
		cout << "Position en x : ";
		cin >> posX;
		cout << endl << "Position en y : ";
		cin >> posY;
		possible = grilleJ.placerBateau(2, orientation, posX, posY);
	}
}