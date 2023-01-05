#include <iostream>
using namespace std;

#include "Croiseur.h"

Croiseur::Croiseur(Position posi, bool orientation) {
	pos = posi;
	isVertical = orientation;
	casesTouchees = { false, false, false, false };
}