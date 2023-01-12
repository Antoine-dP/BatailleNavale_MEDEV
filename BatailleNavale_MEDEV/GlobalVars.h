#pragma once

#include "Windows.h"
#include <iostream>
#include <stdio.h>
#include <vector>

#include "Partie.h"


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
int windowW = 480;
int windowH = 480;

// Affichage Grille
int lineWidth = 4;
int intervalH = (int)((windowH - lineWidth) / 10);
int intervalW = (int)((windowW - lineWidth) / 10);

float coordCarre[4][2]{
    { 0.0, 0.0},
    { 1.0, 0.0},
    { 1.0, 1.0},
    { 0.0, 1.0}
};