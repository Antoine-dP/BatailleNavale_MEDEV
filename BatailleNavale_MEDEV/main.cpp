// BatailleNavale_MEDEV.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//




#include "Partie.h"
#include "GlobalVars.h"

using namespace std;

// Déclarations des fonctions de rappel (callbacks)
GLvoid affichage();
GLvoid clavier(unsigned char touche, int x, int y);
GLvoid redimensionner(int w, int h);


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
    default:
        glFlush();
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

    int intervalH = (int)((windowH - lineWidth) / 10);
    int intervalW = (int)((windowW - lineWidth) / 10);

    cout << intervalW << ", " << intervalH << endl;

    // Projection
    glMatrixMode(GL_PROJECTION);

    // Resetting matrix
    glLoadIdentity();
    glViewport(0, 0, windowW, windowH);

    // Ortho2D
    gluOrtho2D(0, windowW, 0, windowH);

    // Retourne a la pile modelview
    glMatrixMode(GL_MODELVIEW);
}


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////




// Definition de la fonction d'affichage
GLvoid affichage() {
    // Effacement du frame buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    //dessinerGrille();

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
    glClearColor(0.15f, 0.15f, 0.30f, 0.0f);

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
