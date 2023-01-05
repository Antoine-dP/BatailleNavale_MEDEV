#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class SousMarin : public Bateau {
	//Attributs
protected:
	int size = 3;
	//Constructeur 
public:
	SousMarin(Position p, bool orientation);
	//méthode
	
};
