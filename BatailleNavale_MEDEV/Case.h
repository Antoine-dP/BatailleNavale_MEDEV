#pragma once

#include <iostream>
#include "Position.h"
#include"Bateau.h"
#include"ContreTorpilleur.h"

using namespace std;

class Case {
	Position position;
	int etat;
	// 0 : vide
	// 1 : bateau non touché
	// 2 : bateau touché
public:
	Case(Position p, int _etat) {
		position = p;
		etat = _etat;
	}
	Case(int x, int y, int _etat) {
		position.x = x;
		position.y = y;
		etat = _etat;
	}
	//virtual void affiche() = 0;
};