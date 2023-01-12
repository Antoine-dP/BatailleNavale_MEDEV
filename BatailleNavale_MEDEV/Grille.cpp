#include "Grille.h"

// Implémentation du constructeur de la classe Grille
Grille::Grille(int longueur, int largeur)
{
    this->longueur = longueur;
    this->largeur = largeur;
    this->cases = std::vector<std::vector<int>>(longueur, std::vector<int>(largeur, 0));
}

// Implémentation de la méthode afficher de la classe Grille
void Grille::afficher()
{
    for (int i = 0; i < this->longueur; i++)
    {
        for (int j = 0; j < this->largeur; j++)
        {
            std::cout << this->cases[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Implémentation de la méthode placerBateau de la classe Grille
bool Grille::placerBateau(int longueurBateau, char orientation, int x, int y)
{
    if (orientation == 'v')
    {
        // Vérification que le bateau ne dépasse pas de la grille sur l'axe des abscisses
        if (x + longueurBateau > this->longueur)
        {
            std::cout << "Impossible de placer le bateau : il dépasse de la grille sur l'axe des abscisses." << std::endl;
            return false;
        }

        // Vérification que les cases où le bateau doit être placé ne sont pas déjà occupées par un autre bateau
        for (int i = x; i < x + longueurBateau; i++)
        {
            if (this->cases[i][y] != 0)
            {
                std::cout << "Impossible de placer le bateau : la case (" << i << ", " << y << ") est déjà occupée." << std::endl;
                return false;
            }
        }

        // Placement du bateau sur la grille
        for (int i = x; i < x + longueurBateau; i++)
        {
            this->cases[i][y] = 1;
        }
        return true;
    }
    else if (orientation == 'h')
    {
        // Vérification que le bateau ne dépasse pas de la grille sur l'axe des ordonnées
        if (y + longueurBateau > this->largeur)
        {
            std::cout << "Impossible de placer le bateau : il dépasse de la grille sur l'axe des ordonnées." << std::endl;
            return false;
        }

        // Vérification que les cases où le bateau doit être placé ne sont pas déjà occupées par un autre bateau
        for (int j = y; j < y + longueurBateau; j++)
        {
            if (this->cases[x][j] != 0)
            {
                std::cout << "Impossible de placer le bateau : la case (" << x << ", " << j << ") est déjà occupée." << std::endl;
                return false;
            }
        }

        // Placement du bateau sur la grille
        for (int j = y; j < y + longueurBateau; j++)
        {
            this->cases[x][j] = 1;
        }
        return true;
    }
}

bool Grille::tirer(int x, int y)
{
    if (this->cases[x][y] == 1)
    {
        // Si la case contient un bateau (indiqué par la valeur 1),
        // on modifie la valeur de la case pour indiquer que le bateau a été touché
        this->cases[x][y] = 2;
        return true; // On retourne true pour indiquer que le tir a touché un bateau
    }
    else
    {
        // Si la case ne contient pas de bateau (indiqué par la valeur 0),
        // on modifie la valeur de la case pour indiquer que la case a été visée
        this->cases[x][y] = 3;
        return false; // On retourne false pour indiquer que le tir a raté
    }
}

// OPENGL

void Grille::afficheAll() {
	afficheGrille();
	// Affiche les objets dans la grille
    afficheCase();
}

// Dessine un carré
void Grille::dessineLigne(double largeur, double hauteur, int x, int y)
{
    intervalH = (int)((windowH - lineWidth) / 10);
    intervalW = (int)((windowW - lineWidth) / 10);
    // if not pressed, just draw in white
    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.8f, 0.8f);

    for (int j = 0; j < 4; j++)
    {
        glVertex2f(x + largeur * coordCarre[j][0], y + hauteur * coordCarre[j][1]);
    }
    glEnd();
}

//
// Dessine le repere actuel pour faciliter
// la comprehension des transformations.
// Utiliser "echelle" pour avoir un repere bien oriente et positionne
// mais avec une echelle differente.
void  Grille::afficheGrille()
{

    for (int i = 0; i < 11; i++)
    {
        dessineLigne(lineWidth, 10 * intervalH + lineWidth, i * intervalW, 0);
    }
    for (int i = 0; i < 11; i++)
    {
        dessineLigne(10 * intervalW + lineWidth, lineWidth, 0, i * intervalH);
    }
}

//
// Afficher ce qu'il y a dans une case :
// Rien = rien (logik)
// Carré = Bateau
// Croix grise = Tir loupé
// Croix rouge = Tir sur un bateau

void Grille::dessineBateau(int posX, int posY) {
    glBegin(GL_QUADS);

    glColor3f(0.7f, 0.7f, 1.0f);

    // 4 sommets du carré
    for (int j = 0; j < 4; j++)
    {
        glVertex2f((coordForme[j + 1][0] + posX) * intervalW,
                   (coordForme[j + 1][1] + posY) * intervalH);
    }
    glEnd();

}

void Grille::dessineCroix(int i, int j) {

}

void Grille::afficheCase() 
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Juste un bateau
            if (cases[i][j] == 1) {
                dessineBateau(i, j);
            }
            //// Juste un tir loupé
            //else if (cases[i][j] == 3) {
            //    dessineCroix(i, j);
            //}
            //// Un tir réussi
            //else if (cases[i][j] == 2) {
            //    dessineBateau(i, j);
            //    dessineCroix(i, j);
            //}
        }
    }
}