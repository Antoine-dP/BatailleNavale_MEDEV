#pragma once

#include <iostream>
#include "Position.h"
#include"Bateau.h"
#include"ContreTorpilleur.h"

using namespace std;

class Case {
	Position position;
public:
	Case(Position p, int _etat) {
		position = p;
	}
	Case(int x, int y, int _etat) {
		position.x = x;
		position.y = y;
	}
	//virtual void affiche() = 0;
};