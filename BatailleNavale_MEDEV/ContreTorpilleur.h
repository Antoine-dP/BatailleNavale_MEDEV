#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class ContreTorpilleur : public Bateau {
	//Attributs
protected:
	int size = 3;
	//Constructeur 
public:
	ContreTorpilleur(Position, bool);
	//méthode
	
};