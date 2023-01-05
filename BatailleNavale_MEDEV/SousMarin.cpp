#include <iostream>
using namespace std;

#include "SousMarin.h"

SousMarin::SousMarin(Position posi, bool orientation) {
	pos = posi;
	isVertical = orientation;
	casesTouchees = { false, false, false };
}