#include "IA.h"

#include <ctime>
#include <cstdlib>
using namespace std;

IA::IA()
{
	grilleIA.setCouleurGrille(1.0, 0.5, 0.0);
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

bool IA::tireSurIA(int posX, int posY) {
	return grilleIA.tirer(posX, posY);
}