#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include "Case.h"
//#include "Joueur.h"
#include "Position.h"

class Bateau {
	//Attributs 
	protected :
	int size; //taille du bateau
	bool isVertical; //orientation du bateau
	vector<bool> casesTouchees;
	Position pos;//position de la case en haut � gauche du bateau
	//Constructeur

	//M�thodes
	public: 
		void Afficher(/*Joueur*/) {  };
};