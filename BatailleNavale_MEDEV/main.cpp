// BatailleNavale_MEDEV.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


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

#include "Partie.h"

using namespace std;

float coordCarre[4][2]{
    { 0.0, 0.0},
    { 1.0, 0.0},
    { 1.0, 1.0},
    { 0.0, 1.0}
};


// Rotations autour de X et Y
GLboolean boutonClick = false;

// Taille de la fenêtre
int windowW = 640*2;
int windowH = 480*2;

// Déclarations des fonctions de rappel (callbacks)
GLvoid affichage();
GLvoid clavier(unsigned char touche, int x, int y);
GLvoid redimensionner(int w, int h);

void dessineRectangle(double largeur, double hauteur);
void dessinerGrille(unsigned int echelle = 1);


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

// Definition de la fonction gerant les interruptions clavier
GLvoid clavier(unsigned char touche, int x, int y) {

    // Suivant les touches pressees, nous aurons un comportement different de l'application
    // ESCAPE ou 'q' : fermera l'application
    // ESCAPE ou 'q' : fermera l'application

    switch (touche) {
    case 'd':
        glEnable(GL_DEPTH_TEST);
        glutPostRedisplay();
        break;
    case 'D':
        glDisable(GL_DEPTH_TEST);
        glutPostRedisplay();
        break;

    case 'q': // quitter
    case 27:
        exit(0);
        break;


        // A vous de gerer le reste
    }

    // Demande a GLUT de reafficher la scene
    glutPostRedisplay();
}



// Callback de redimensionnement de la fenêtre
GLvoid redimensionner(int w, int h) {
    // Garde les valeurs
    windowW = w;
    windowH = h;
    // eviter une division par 0
    if (windowH == 0)
        windowH = 1;

    float ratio = (float)windowW / (float)windowH;
    std::cout << "Ratio : " << ratio << std::endl;

    // Projection
    glMatrixMode(GL_PROJECTION);

    // Resetting matrix
    glLoadIdentity();

    // Ortho2D
    gluOrtho2D(0, windowW, 0, windowH);

    // Retourne a la pile modelview
    glMatrixMode(GL_MODELVIEW);
}


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


//
// Dessine un carré
void dessineRectangle(double largeur, double hauteur)
{
    // if not pressed, just draw in white
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);
    
    for (int j = 0; j < 4; j++)
    {
        glVertex2f(coordCarre[j][0] * 1000 + 100, coordCarre[j][1] * 10 + 100);
    }
    glEnd();
}

//
// Dessine le repere actuel pour faciliter
// la comprehension des transformations.
// Utiliser "echelle" pour avoir un repere bien oriente et positionne
// mais avec une echelle differente.
void dessinerGrille(unsigned int echelle)
{

}

// Definition de la fonction d'affichage
GLvoid affichage() {
    // Effacement du frame buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    dessineRectangle(1, 1);

    glFlush();
    glutSwapBuffers();
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
    // Initialisation de GLUT
    glutInit(&argc, argv);
    // Choix du mode d'affichage (ici RVB)
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    // Position initiale de la fenetre GLUT
    glutInitWindowPosition(250, 50);
    // Taille initiale de la fenetre GLUT
    glutInitWindowSize(windowW, windowH);
    // Creation de la fenetre GLUT
    glutCreateWindow("Bataille Navale");

    // Définition de la couleur d'effacement du framebuffer
    glClearColor(0.10f, 0.10f, 0.10f, 0.0f);

    // Initialement on active le Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Shading model
    glShadeModel(GL_SMOOTH);

    // Définition des fonctions de callbacks
    glutDisplayFunc(affichage);
    glutKeyboardFunc(clavier);
    glutReshapeFunc(redimensionner);

    // Lancement de la boucle infinie GLUT
    glutMainLoop();

    return 0;
}
