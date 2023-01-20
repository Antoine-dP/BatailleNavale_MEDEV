#pragma once

#include <iostream>
#include <vector>
#include "GlobalVars.h"
using namespace std;

// Définition de la classe Grille qui représente la grille de jeu
class Grille
{
protected:
    // Attributs privés de la classe Grille
    int longueur;
    int largeur;

    // Couleur de la grille
    vector<float> couleur_grille;

    //int bateau;
    std::vector<std::vector<int>> cases;

public:
    // Constructeur de la classe Grille
    Grille();
    Grille(int longueur, int largeur);

    
    // Accesseurs/ Setteurs
    vector<float> getCouleurGrille() { return couleur_grille; }
    void setCouleurGrille(float r, float g, float b) { 
        couleur_grille[0] = r;
        couleur_grille[1] = g;
        couleur_grille[2] = b;
    }
    int getLongueur() { return longueur; }
    int getLargeur() { return largeur; }
    int getCase(int i, int j) { return cases[i][j]; }
    void setCase(int i, int j, int valeur) { cases[i][j] = valeur; }

    // Méthodes publiques de la classe Grille
    void afficher(); // Afficher dans la commande
    bool placerBateau(int longueurBateau, bool horizontal, int x, int y);
    bool tirer(int x, int y);

    // OPENGL
    void afficheAll();
    void afficheGrille();
    void dessineLigne(double largeur, double hauteur, int x, int y);
    void afficheCase();
    void dessineUnCarre(int i, int j, bool couleurClaire);
    void dessineBateau(int taille, bool orientation, int posX, int posY);
    void dessineCroix(int i, int j, bool touche);
};