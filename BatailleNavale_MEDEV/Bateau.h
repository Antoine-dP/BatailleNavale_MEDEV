#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include "Case.h"
//#include "Joueur.h"

class Bateau {
	//Attributs 
	protected :
	int size; //taille du bateau
	bool isVertical; //orientation du bateau
	vector<bool> casesTouchees;
	//Constructeur

	//Méthodes
	public: 
	//virtual void Afficher(Joueur) const = 0;
};