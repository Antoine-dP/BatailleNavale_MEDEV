#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class Croiseur : public Bateau {
	//Attributs
protected:
	int size = 5;
	//Constructeur 
public:
	Croiseur();
	//méthode
	//void Afficher(Joueur) const = 0;
};