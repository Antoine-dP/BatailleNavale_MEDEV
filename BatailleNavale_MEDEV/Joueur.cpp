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
	cout << "Placement Porte Avion (5 cases) : " << endl;
	cout << "Orientation (h ou v) : ";
	cin >> orientation;
	cout << endl;
	cout << "Position en x : ";
	cin >> posX;
	cout << endl << "Position en y : ";
	cin >> posY;
	grilleJ.placerBateau(5, orientation, posX, posY);




}