#include "GlobalVars.h"

int windowW = 480;
int windowH = 480;

int lineWidth = 4;
int intervalH = (int)((windowH - lineWidth) / 10);
int intervalW = (int)((windowW - lineWidth) / 10);

float coordCarre[4][2]{
    { 0.0, 0.0},
    { 1.0, 0.0},
    { 1.0, 1.0},
    { 0.0, 1.0}
};