#pragma once

#include <iostream>
using namespace std;

#include "Bateau.h"

class SousMarin : public Bateau {
	//Attributs
protected:
	//Constructeur 
public:
	SousMarin(Position p, bool orientation) :Bateau(p, orientation, 3) {};
	SousMarin(int x, int y, bool orientation) :Bateau(x, y, orientation, 3) {};
	//méthode
	
};
