#pragma once

#include <iostream>
#include "Position.h"

using namespace std;

class Case {
	Position position;
public:
	Case(Position p) {
		position = p;
	}
	Case(int x, int y) {
		position.x = x;
		position.y = y;
	}
	virtual void affiche() = 0;
};