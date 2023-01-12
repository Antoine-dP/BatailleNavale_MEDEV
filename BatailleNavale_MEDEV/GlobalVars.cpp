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

// Pour dessiner les carré des bateaux
float coordForme[5][2]{
    { 0.5f, 0.5f}, // centre du carré
    { 0.1f, 0.1f}, // bas à gauche du carré
    { 0.9f, 0.1f},
    { 0.9f, 0.9f},
    { 0.1f, 0.9f}
};

// Variables pour ajuster l'affichage au centre des cases
float ajustementX = 0.045;
float ajustementY = 0.045;