// BatailleNavale_MEDEV.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Joueur.h"
#include "IA.h"
#include "GlobalVars.h"
#include "Partie.h"

using namespace std;


// Déclarations des fonctions de rappel (callbacks)
GLvoid affichage();
GLvoid clavier(unsigned char touche, int x, int y);
GLvoid redimensionner(int w, int h);

void dessineRectangle(double largeur, double hauteur);
void dessinerGrille(unsigned int echelle = 1);

Grille grille;


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

// Definition de la fonction gerant les interruptions clavier
GLvoid clavier(unsigned char touche, int x, int y) {

    // Suivant les touches pressees, nous aurons un comportement different de l'application
    // ESCAPE ou 'q' : fermera l'application
    // ESCAPE ou 'q' : fermera l'application
    
    switch (touche) {
    /*case 'd':
        glEnable(GL_DEPTH_TEST);
        glutPostRedisplay();
        break;
    case 'D':
        glDisable(GL_DEPTH_TEST);
        glutPostRedisplay();
        break;*/

    // Validation du placement d'un bateau pendant l'initialisation de la partie
    case 13:
    case 'a':
        if (!partieInitialisee && grille.placerBateau(taille, horizontal, placementX, placementY)) {
            // On réinitialise la position du prochain bateau à placer
            placementX = 0;
            placementY = 10;

            // on donne la bonne taille au prochain bateau
            numBateau++;
            if (numBateau < 3) {
                taille = numBateau + 1;
            }
            else {
                taille = numBateau;
            }

            if (numBateau > 5) {
                partieInitialisee = true;
            }
        }
        break;
    case 'r':
        horizontal = !horizontal;
        break;
    case 's':
        cout << "down\n";
        placementY = placementY - 1;
        break;
    case 'z':
        cout << "up\n";
        placementY++;
        break;
    case 'q':
        cout << "left\n";
        placementX = placementX - 1;
        break;
    case 'd':
        cout << "right\n";
        placementX++;
        break;    
    case 27:
        exit(0);
        break;
    }

    // On gère les possibles dépassements
    if (horizontal) {
        if (placementY > 9) { placementY = 9; }
        else if (placementY < 0) { placementY = 0; }
        if (placementX + taille > 9) { placementX = 9 - (taille - 1); }
        else if (placementX < 0) { placementX = 0; }
    }
    else {
        if (placementY > 9) { placementY = 9 ; }
        else if (placementY - taille < 0) { placementY = 0 + (taille-1); }
        if (placementX> 9) { placementX = 9; }
        else if (placementX < 0) { placementX = 0; }
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

    glViewport(0, 0, windowW, windowH);

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

    grille.afficheAll();

    // dessin du bateau pendant l'initialisation de la partie
    if (!partieInitialisee) {
        grille.dessineBateau(taille, horizontal, placementX, placementY);
    }

    glFlush();
    glutSwapBuffers();
}



///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
    Partie partie;
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
    glClearColor(0.10f, 0.10f, 0.40f, 0.0f);

    // Initialement on active le Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Shading model
    glShadeModel(GL_SMOOTH);

    // Définition des fonctions de callbacks
    glutDisplayFunc(affichage);
    glutKeyboardFunc(clavier);
    glutReshapeFunc(redimensionner);

    partie.initialisationPartie();

    // Lancement de la boucle infinie GLUT
    glutMainLoop();
    return 0;
}
