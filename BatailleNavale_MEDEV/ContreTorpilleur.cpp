#include <iostream>
using namespace std;

#include "ContreTorpilleur.h"

ContreTorpilleur::ContreTorpilleur(Position posi, bool orientation) {
	pos = posi;
	isVertical = orientation;
	casesTouchees = { false, false, false };
}
