#pragma once

#include <iostream>
#include <vector>
#include "GlobalVars.h"
using namespace std;

// D�finition de la classe Grille qui repr�sente la grille de jeu
class Grille
{
protected:
    // Attributs priv�s de la classe Grille
    int longueur;
    int largeur;
    //int bateau;
    std::vector<std::vector<int>> cases;

public:
    // Constructeur de la classe Grille
    Grille();
    Grille(int longueur, int largeur);


    // M�thodes publiques de la classe Grille
    void initialisationGrilleAI();
    void afficher(); // Afficher dans la commande
    bool placerBateau(int longueurBateau, bool horizontal, int x, int y);
    bool tirer(int x, int y);

    int getLongueur() { return longueur; }
    int getLargeur() { return largeur; }
    int getCase(int i, int j) { return cases[i][j]; }
    void setCase(int i, int j, int valeur) { cases[i][j] = valeur; }

    // OPENGL
    void afficheAll();
    void afficheGrille();
    void dessineLigne(double largeur, double hauteur, int x, int y);
    void afficheCase();
    void dessineUnCarre(int i, int j, bool couleurClaire);
    void dessineBateau(int taille, bool orientation, int posX, int posY);
    void dessineCroix(int i, int j, bool touche);
};