#pragma once

#include <iostream>
#include <vector>

// D�finition de la classe Grille qui repr�sente la grille de jeu
class Grille
{
private:
    // Attributs priv�s de la classe Grille
    int longueur;
    int largeur;
    std::vector<std::vector<int>> cases;

public:
    // Constructeur de la classe Grille
    Grille(int longueur, int largeur);

    // M�thodes publiques de la classe Grille
    void afficher(); // Afficher dans la commande
    void placerBateau(int longueurBateau, char orientation, int x, int y);
    bool tirer(int x, int y);

    int getLongueur() { return longueur; }
    int getLargeur() { return largeur; }
    int getCase(int i, int j) { return cases[i][j]; }
    void setCase(int i, int j, int valeur) { cases[i][j] = valeur; }

    // OPENGL
    void afficheAll();
    void afficheGrille();
    void dessineLigne(double largeur, double hauteur, int x, int y);

};