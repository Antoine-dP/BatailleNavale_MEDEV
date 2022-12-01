#pragma once

#include <iostream>
#include <vector>

#include "Position.h"
#include "Case.h"

using namespace std;


class Grille {
	vector<Case*> caseVect;
public:
	Grille() {};
	void afficheAll();
	void afficheGrille();
};