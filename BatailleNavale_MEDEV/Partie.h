#pragma once
#include "Joueur.h"
#include "IA.h"

using namespace std;

class Partie
{
private:
	Joueur _joueur;
	IA _ia;

public:
	Partie();
	Partie(Joueur j, IA i);
	~Partie();

	//void debutPartie();
	//void jouerTour();
	bool partieFinie();
	void finDePartie(bool joueurGagne);

};

