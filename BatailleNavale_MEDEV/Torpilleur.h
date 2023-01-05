#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class Torpilleur : public Bateau {
	//Attributs
protected:
	int size = 2;
	//Constructeur 
public:
	Torpilleur(Position, bool);
	//méthode
	
};