#include "IA.h"

#include <ctime>
#include <cstdlib>
using namespace std;

IA::IA()
{
}

IA::IA(int longueur, int largeur)
{
	grilleIA = Grille(longueur, largeur);
}

IA::~IA()
{
}

bool IA::initialiser() {
	// Pour placer les bateaux sur la grille de l'IA
	int tailleBateau;
	int numBateau = 5;
	int posx = rand() % 10;
	int posy = rand() % 10;
	bool horizontal = rand() % 2;

	while (numBateau > 0) {
		// on donne la bonne taille au bateau
		if (numBateau < 3) {
			tailleBateau = numBateau + 1;
		}
		else {
			tailleBateau = numBateau;
		}

		// Tire au sort position et orientation
		// tant que les emplacements ne sont pas libres
		while (!grilleIA.placerBateau(tailleBateau, horizontal, posx, posy)) {
			posx = rand() % 10;
			posy = rand() % 10;
			horizontal = rand() % 2;
		}

		// Il vaut mieux commencer par le plus gros pour éviter
		// de devoir chercher une place trop longtemps
		numBateau = numBateau - 1;
	}
	return true;
}

// Initializing random number generator in C++ (0 to 9)
int randomNumber() {
	srand(time(0));
	return rand() % 10;
}

char randomOrientation() {
	srand(time(0));
	if (rand() % 2 == 0) {
		return 'h';
	}
	else {
		return 'v';
	}
}

/*
void IA::placerBateaux() {
	int posX, posY;
	char orientation;
	bool possible = false;

	// Bateau 1 : (Porte Avion 5 cases)
	while (!possible) {
		orientation = randomOrientation();
		posX = randomNumber();
		posY = randomNumber();
		possible = grilleIA.placerBateau(5, orientation, posX, posY);
	}

	possible = false;
	// Bateau 2 : (Croiseur 4 cases)
	while (!possible) {
		orientation = randomOrientation();
		posX = randomNumber();
		posY = randomNumber();
		possible = grilleIA.placerBateau(4, orientation, posX, posY);
	}

	possible = false;
	// Bateau 3 : (Sous-marin 3 cases)
	while (!possible) {
		orientation = randomOrientation();
		posX = randomNumber();
		posY = randomNumber();
		possible = grilleIA.placerBateau(3, orientation, posX, posY);
	}

	possible = false;
	// Bateau 4 : (Sous-marin 3 cases)
	while (!possible) {
		orientation = randomOrientation();
		posX = randomNumber();
		posY = randomNumber();
		possible = grilleIA.placerBateau(3, orientation, posX, posY);
	}

	possible = false;
	// Bateau 5 : (Torpilleur 2 cases)
	while (!possible) {
		orientation = randomOrientation();
		posX = randomNumber();
		posY = randomNumber();
		possible = grilleIA.placerBateau(2, orientation, posX, posY);
	}
}
*/

bool IA::tirer(Grille grilleJoueur) {
	int posX, posY;
	posX = randomNumber();
	posY = randomNumber();
	return grilleJoueur.tirer(posX, posY);
}