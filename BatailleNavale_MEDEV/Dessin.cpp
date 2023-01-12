
#include "Dessin.h"


float coordForme[5][2]{
    { 0.5f, 0.5f}, // centre du carré
    { 0.1f, 0.1f}, // bas à gauche du carré
    { 0.9f, 0.1f},
    { 0.9f, 0.9f},
    { 0.1f, 0.9f}
};

//
// Dessine un triangle (extrémité d'un bateau)
// orientation : 0=bas, 1=droite, 2=haut, 3=gauche
void dessineTriangle(Position pos, double largeur, double hauteur, int orientation)
{
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);

    // Point au centre du carré (ne change jamais)
    glVertex2f((coordForme[0][0] + pos.x) * largeur, (coordForme[0][1] + pos.y) * hauteur);

    // 2 autres points (varient selon l'orientation du bateau)
    for (int j = 1; j < 3; j++)
    {
        if (j + orientation == 5) {
            orientation = -1; // comme ça j+orientation = 1
        }

        glVertex2f((coordForme[j + orientation][0] + pos.x) * largeur,
            (coordForme[j + orientation][1] + pos.y) * hauteur);
    }
    glEnd();
    // if not pressed, just draw in white

}

//
// Dessine un carré (corps d'un bateau)
void dessineCarre(Position pos, double largeur, double hauteur) {
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // 4 sommets du carré
    for (int j = 0; j < 4; j++)
    {

        glVertex2f((coordForme[j + 1][0] + pos.x) * largeur,
            (coordForme[j + 1][1] + pos.y) * hauteur);
    }
    glEnd();
}

//
// Dessine un torpilleur (size = 2)
void dessineTorpilleur(Position pos, double largeur, double hauteur, bool isVertical) {
    int orientation2 = 2;
    int orientation1 = 0;

    if (!isVertical) {
        orientation2 = 3;
        orientation1 = 1;
    }

    // dessine le triangle dans la 2eme case
    dessineTriangle(pos, largeur, largeur, orientation2);

    pos.y += 1.0f;
    // dessine le triangle dans la 1ere case
    dessineTriangle(pos, largeur, largeur, orientation1);

}

//
// Dessine un SousMarin ou un ContreTorpilleur (size = 3)
void dessineSMouCT(Position pos, double largeur, double hauteur, bool isVertical) {

    if (isVertical) {
        // dessine le triangle dans la 3eme case
        dessineTriangle(pos, largeur, hauteur / 3, 2);

        pos.y += 1.0f;
        // dessine carré dans la 2eme case
        dessineCarre(pos, largeur, hauteur / 3);

        pos.y += 1.0f;
        // dessine le triangle dans la 1ere case
        dessineTriangle(pos, largeur, hauteur / 3, 0);
    }
    else {
        // dessine le triangle dans la 1ere case
        dessineTriangle(pos, largeur / 3, hauteur, 1);

        pos.x += 1.0f;
        // dessine carré dans la 2eme case
        dessineCarre(pos, largeur / 3, hauteur);

        pos.x += 1.0f;
        // dessine le triangle dans la 3eme case
        dessineTriangle(pos, largeur / 3, hauteur, 3);
    }
}

//
// Dessine un Croiseur (size = 4)
void dessineCroiseur(Position pos, double largeur, double hauteur, bool isVertical) {

    if (isVertical) {
        // dessine le triangle dans la 4eme case
        dessineTriangle(pos, largeur, hauteur / 4, 2);

        pos.y += 1.0f;
        // dessine carré dans la 3eme case
        dessineCarre(pos, largeur, hauteur / 4);

        pos.y += 1.0f;
        // dessine carré dans la 2eme case
        dessineCarre(pos, largeur, hauteur / 4);

        pos.y += 1.0f;
        // dessine le triangle dans la 1ere case
        dessineTriangle(pos, largeur, hauteur / 4, 0);
    }
    else {
        // dessine le triangle dans la 1ere case
        dessineTriangle(pos, largeur / 4, hauteur, 1);

        pos.x += 1.0f;
        // dessine carré dans la 2eme case
        dessineCarre(pos, largeur / 4, hauteur);

        pos.x += 1.0f;
        // dessine carré dans la 3eme case
        dessineCarre(pos, largeur / 4, hauteur);

        pos.x += 1.0f;
        // dessine le triangle dans la 4eme case
        dessineTriangle(pos, largeur / 4, hauteur, 3);
    }
}

//
// Dessine un PorteAvion (size = 5)
void dessinePorteAvion(Position pos, double largeur, double hauteur, bool isVertical) {

    if (isVertical) {
        // dessine le triangle dans la 5eme case
        dessineTriangle(pos, largeur, hauteur / 5, 2);

        pos.y += 1.0f;
        // dessine carré dans la 4eme case
        dessineCarre(pos, largeur, hauteur / 5);

        pos.y += 1.0f;
        // dessine carré dans la 3eme case
        dessineCarre(pos, largeur, hauteur / 5);
                                             
        pos.y += 1.0f;                       
        // dessine carré dans la 2eme case   
        dessineCarre(pos, largeur, hauteur / 5);

        pos.y += 1.0f;
        // dessine le triangle dans la 1ere case
        dessineTriangle(pos, largeur, hauteur / 5, 0);
    }
    else {
        // dessine le triangle dans la 1ere case
        dessineTriangle(pos, largeur / 5, hauteur, 1);

        pos.x += 1.0f;
        // dessine carré dans la 2eme case
        dessineCarre(pos, largeur / 5, hauteur);

        pos.x += 1.0f;
        // dessine carré dans la 3eme case
        dessineCarre(pos, largeur / 5, hauteur);

        pos.x += 1.0f;
        // dessine carré dans la 4eme case
        dessineCarre(pos, largeur / 5, hauteur);

        pos.x += 1.0f;
        // dessine le triangle dans la 5eme case
        dessineTriangle(pos, largeur / 5, hauteur, 3);
    }
}

