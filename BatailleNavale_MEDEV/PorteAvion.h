#pragma once


#include <iostream>
using namespace std;

#include "Bateau.h"

class PorteAvion : public Bateau {
	//Attributs
	protected:
	int size = 5;
	//Constructeur 
	public:	
	PorteAvion(Position, bool);
	//méthode
	
};