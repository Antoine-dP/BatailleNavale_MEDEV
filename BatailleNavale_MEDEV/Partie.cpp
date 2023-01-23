#include "Partie.h"

Partie::Partie()
{
}

Partie::Partie(Joueur j, IA i)
{
	_joueur = j;
	_ia = i;
}

Partie::~Partie()
{
}

bool Partie::partieFinie() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (_joueur.getGrille().getCase(i, j) == 1 || _ia.getGrille().getCase(i, j) == 1) {
				return false;
			}
		}
	}
	return true;
}


void vBitmapOutput(int x, int y, const char* string, void* font)
{
	int len; // len donne la longueur de la chaîne de caractères

	glRasterPos2f(x, y); // Positionne le premier caractère de la chaîne
	len = (int)strlen(string); // Calcule la longueur de la chaîne
	for (int i = 0; i < len; i++) glutBitmapCharacter(font, string[i]); // Affiche chaque caractère de la chaîne
}


void Partie::finDePartie(bool joueurGagne) {
	const char* texteDeFin;
	if (joueurGagne) {
		texteDeFin = "Vous avez gagne ! Bravo !";
		PlaySound(TEXT("sons\\victoire.wav"), NULL, SND_SYNC);
	}
	else {
		texteDeFin = "T'as perdu gros noob";
		PlaySound(TEXT("sons\\defaite.wav"), NULL, SND_SYNC);
	}

	cout << endl << texteDeFin;
	vBitmapOutput(windowW / 6, windowH / 2, texteDeFin, GLUT_BITMAP_TIMES_ROMAN_24);
}