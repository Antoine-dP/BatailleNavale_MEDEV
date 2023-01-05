#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class Croiseur : public Bateau {
	//Attributs
protected:
	//Constructeur 
public:
	Croiseur(Position p, bool orientation) :Bateau(p, orientation, 4) {};
	Croiseur(int x, int y, bool orientation) :Bateau(x, y, orientation, 4) {};
	//méthode
};