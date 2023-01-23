#pragma once

#include "Windows.h"
#include <iostream>
#include <stdio.h>
#include <vector>



// Fichiers d'en-têtes pour OpenGL et GLUT
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
//#define GLFW_INCLUDE_NONE
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>


#define GL_GLEXT_PROTOTYPES

#endif

// Taille de la fenêtre
extern int windowW;
extern int windowH;

// Affichage Grille
extern int lineWidth;
extern int intervalH;
extern int intervalW;

extern float coordCarre[4][2];

extern float coordForme[5][2];

extern float coordCroixCasse[4][2];
extern float coordCroixContreCasse[4][2];

extern float ajustementX;
extern float ajustementY;

//
// TEST
extern int placementX;
extern int placementY;

extern int taille;
extern int numBateau;

extern bool horizontal;

extern bool partieInitialisee;
extern bool afficheJoueur;
extern bool partieFinie;
extern bool joueurGagne;