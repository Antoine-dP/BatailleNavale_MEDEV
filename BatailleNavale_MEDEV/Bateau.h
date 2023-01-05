#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include "Case.h"
//#include "Joueur.h"
#include "Position.h"

class Bateau : public Case{
	//Attributs 
	protected :
	int size; //taille du bateau
	bool isVertical; //orientation du bateau
	vector<bool> casesTouchees;

	//Méthodes
	public: 
		//Constructeur
		Bateau(Position p, bool orientation, int taille) : Case(p) {
			for (int i = 0; i < taille; i++) { casesTouchees.push_back(false); };
		};
		Bateau(int x, int y, bool orientation, int taille) : Case(x, y) {
			for (int i = 0; i < taille; i++) { casesTouchees.push_back(false); };
		};

		void Afficher(/*Joueur*/) {  };
};