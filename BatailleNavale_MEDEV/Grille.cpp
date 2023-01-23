#include "Grille.h"

// Implémentation du constructeur de la classe Grille
Grille::Grille()
{
    this->longueur = 10;
    this->largeur = 10;
    this->cases.resize(largeur, std::vector<int>(longueur, 0));
    for (int i = 0; i < 3; i++) {
        this->couleur_grille.push_back(0.8f);
    }
}

Grille::Grille(int longueur, int largeur)
{
    this->longueur = longueur;
    this->largeur = largeur;
    this->cases.resize(largeur, std::vector<int>(longueur, 0));
    for (int i = 0; i < 3; i++) {
        this->couleur_grille.push_back(0.8f);
    }
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
bool Grille::placerBateau(int longueurBateau, bool horizontal, int x, int y)
{
    if (horizontal)
    {
        // Vérification que le bateau ne dépasse pas de la grille sur l'axe des abscisses
        if (x + longueurBateau > 9)
        {
            //std::cout << "Impossible de placer le bateau : il dépasse de la grille sur l'axe des abscisses." << std::endl;
            return false;
        }

        // Vérification que les cases où le bateau doit être placé ne sont pas déjà occupées par un autre bateau
        for (int i = x - 1; i < x + longueurBateau + 1; i++)
        {
            if (i >= 0 && i < 10) {
                if (this->cases[i][y] != 0 || (y < 9 && this->cases[i][y + 1] != 0) || (y > 1 && this->cases[i][y - 1] != 0))
                {
                    //std::cout << "Impossible de placer le bateau : la case (" << i << ", " << y << ") est déjà occupée." << std::endl;
                    return false;
                }
            }
        }

        // Placement du bateau sur la grille
        for (int i = x; i < x + longueurBateau; i++)
        {            
            this->cases[i][y] = 1;
        }
        return true;
    }
    else
    {
        // Vérification que le bateau ne dépasse pas de la grille sur l'axe des ordonnées
        if (y - (longueurBateau-1) < 0 )
        {
            //std::cout << "Impossible de placer le bateau : il dépasse de la grille sur l'axe des ordonnées." << std::endl;
            return false;
        }

        // Vérification que les cases où le bateau doit être placé ne sont pas déjà occupées par un autre bateau
        for (int j = y + 1; j > y - longueurBateau - 1; j--)
        {
            if (j >= 0 && j < 10) {
                if (this->cases[x][j] != 0 || (x < 9 && this->cases[x + 1][j] != 0) || (x > 1 && this->cases[x-1][j] != 0))
                {
                    //std::cout << "Impossible de placer le bateau : la case (" << x << ", " << j << ") est déjà occupée." << std::endl;
                    return false;
                }
            }
        }

        // Placement du bateau sur la grille
        for (int j = y; j > y - longueurBateau; j--)
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
        cout << "touché\n";
        this->cases[x][y] = 2;

        // On verifie qu'il reste encore des bateaux à toucher dans la grille
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (this->cases[i][j] == 1) {
                    return true;
                }
            }
        }

        // Il n'y a plus de bateau à toucher, la partie est finie
        partieFinie = true;
        return true; // On retourne true pour indiquer que le tir a été effectué
    }
    else if (this->cases[x][y] == 0)
    {
        // Si la case ne contient pas de bateau (indiqué par la valeur 0),
        // on modifie la valeur de la case pour indiquer que la case a été visée
        this->cases[x][y] = 3;
        return true; // On retourne false pour indiquer que le tir a été effectué
    }
    else {
        // le joueur n'a rien touché
        cout << "loupé\n";
        return false;
    }
}

void Grille::tireNaifIA() {
    int posX, posY;
    posX = rand() % 10;
    posY = rand() % 10;

    tirer(posX, posY);
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

    glColor3f(couleur_grille[0], couleur_grille[1], couleur_grille[2]);

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

void Grille::dessineUnCarre(int posX, int posY, bool couleurClaire) {
    glBegin(GL_QUADS);

    if (couleurClaire) {
        glColor3f(0.9f, 0.9f, 1.0f);
    }
    else {
        glColor3f(0.7f, 0.7f, 0.9f);
    }

    // 4 sommets du carré
    for (int j = 0; j < 4; j++)
    {
        glVertex2f((coordForme[j + 1][0] + posX + ajustementX) * intervalW ,
                   (coordForme[j + 1][1] + posY + ajustementY) * intervalH );
    }
    glEnd();

}

void Grille::dessineBateau(int taille, bool horizontal, int posX, int posY) {
    if (horizontal) {
        for (int i = 0; i < taille; i++) {
            dessineUnCarre(posX + i, posY, true);
        }
    }
    else {
        for (int i = 0; i < taille; i++) {
            dessineUnCarre(posX, posY - i, true);
        }
    }
}

void Grille::dessineCroix(int posX, int posY) {
    glBegin(GL_QUADS);

    if (cases[posX][posY] == 2) {
        glColor3f(1.0f, 0.4f, 0.4f);
    }
    else if (cases[posX][posY] == 3) {
        glColor3f(0.7f, 0.7f, 0.7f);
    }
    else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    // 4 sommets du carré
    for (int j = 0; j < 4; j++)
    {
        glVertex2f((coordCroixCasse[j][0] + posX + ajustementX) * intervalW,
            (coordCroixCasse[j][1] + posY + ajustementY) * intervalH);
    }

    for (int j = 0; j < 4; j++)
    {
        glVertex2f((coordCroixContreCasse[j][0] + posX + ajustementX) * intervalW,
            (coordCroixContreCasse[j][1] + posY + ajustementY) * intervalH);
    }
    glEnd();
}


void Grille::afficheCase() 
{
    // on vérifie que les cases existent
    if (cases.size() > 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                // Juste un bateau
                // seulement pour la grille du joueur
                if (afficheJoueur && cases[i][j] == 1) {
                    dessineUnCarre(i, j, false);
                }
                // Juste un tir loupé
                else if (cases[i][j] == 3) {
                    dessineCroix(i, j);
                }
                // Un tir réussi
                else if (cases[i][j] == 2) {
                    dessineCroix(i, j);
                    dessineUnCarre(i, j, false);
                }
            }
        }
    }    
}