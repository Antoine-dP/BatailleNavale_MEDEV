#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class ContreTorpilleur : public Bateau {
	//Attributs
protected:
	//Constructeur 
public:
	ContreTorpilleur(Position p, bool orientation) :Bateau(p, orientation, 3) {};
	ContreTorpilleur(int x, int y, bool orientation) :Bateau(x, y, orientation, 3) {};
	//méthode
	
};