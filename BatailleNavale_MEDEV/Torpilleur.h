#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class Torpilleur : public Bateau {
	//Attributs
protected:
	//Constructeur 
public:
	Torpilleur(Position p, bool orientation) :Bateau(p, orientation, 2) {};
	Torpilleur(int x, int y, bool orientation) :Bateau(x, y, orientation, 2) {};
	//méthode
	
};