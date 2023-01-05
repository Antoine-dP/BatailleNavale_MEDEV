#include <iostream>
using namespace std;

#include "Torpilleur.h"

Torpilleur::Torpilleur(Position posi, bool orientation) {
	pos = posi;
	isVertical = orientation;
	casesTouchees = { false, false };
}