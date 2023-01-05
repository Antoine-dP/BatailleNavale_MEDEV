#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class Croiseur : public Bateau {
	//Attributs
protected:
	int size = 4;
	//Constructeur 
public:
	Croiseur(Position p, bool orientation);
	//méthode
};