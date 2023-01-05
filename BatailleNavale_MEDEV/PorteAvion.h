#pragma once


#include <iostream>
using namespace std;

#include "Bateau.h"

class PorteAvion : public Bateau {
	//Attributs
	protected:
	//Constructeur 
	public:	
	PorteAvion(Position p, bool orientation) :Bateau(p, orientation, 5) {};
	PorteAvion(int x, int y, bool orientation) :Bateau(x, y, orientation, 5) {};
	//méthode
	
};