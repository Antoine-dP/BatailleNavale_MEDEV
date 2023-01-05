#include <iostream>
using namespace std;

#include "PorteAvion.h"

PorteAvion::PorteAvion(Position posi, bool orientation) {
	pos = posi;
	isVertical = orientation;
	casesTouchees = { false, false, false, false, false };
}