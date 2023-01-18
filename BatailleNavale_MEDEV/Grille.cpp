#include "Grille.h"

// Impl�mentation du constructeur de la classe Grille
Grille::Grille()
{
    this->longueur = 10;
    this->largeur = 10;
    this->cases.resize(largeur, std::vector<int>(longueur, 0));
}

Grille::Grille(int longueur, int largeur)
{
    this->longueur = longueur;
    this->largeur = largeur;
    this->cases.resize(largeur, std::vector<int>(longueur, 0));
}

// Impl�mentation de la m�thode afficher de la classe Grille
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

// Impl�mentation de la m�thode placerBateau de la classe Grille
bool Grille::placerBateau(int longueurBateau, bool horizontal, int x, int y)
{
    if (horizontal)
    {
        // V�rification que le bateau ne d�passe pas de la grille sur l'axe des abscisses
        if (x + longueurBateau > 9)
        {
            std::cout << "Impossible de placer le bateau : il d�passe de la grille sur l'axe des abscisses." << std::endl;
            return false;
        }

        // V�rification que les cases o� le bateau doit �tre plac� ne sont pas d�j� occup�es par un autre bateau
        for (int i = x; i < x + longueurBateau; i++)
        {
            if (this->cases[i][y] != 0)
            {
                std::cout << "Impossible de placer le bateau : la case (" << i << ", " << y << ") est d�j� occup�e." << std::endl;
                return false;
            }
        }

        // Placement du bateau sur la grille
        for (int i = x; i < x + longueurBateau; i++)
        {
            cout << cases.size() << endl;
            cout << cases[0].size() << endl;
            this->cases[i][y] = 1;
        }
        return true;
    }
    else
    {
        // V�rification que le bateau ne d�passe pas de la grille sur l'axe des ordonn�es
        if (y - (longueurBateau-1) < 0 )
        {
            std::cout << "Impossible de placer le bateau : il d�passe de la grille sur l'axe des ordonn�es." << std::endl;
            return false;
        }

        // V�rification que les cases o� le bateau doit �tre plac� ne sont pas d�j� occup�es par un autre bateau
        for (int j = y; j > y - longueurBateau; j--)
        {
            if (this->cases[x][j] != 0)
            {
                std::cout << "Impossible de placer le bateau : la case (" << x << ", " << j << ") est d�j� occup�e." << std::endl;
                return false;
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
        // Si la case contient un bateau (indiqu� par la valeur 1),
        // on modifie la valeur de la case pour indiquer que le bateau a �t� touch�
        this->cases[x][y] = 2;
        return true; // On retourne true pour indiquer que le tir a touch� un bateau
    }
    else
    {
        // Si la case ne contient pas de bateau (indiqu� par la valeur 0),
        // on modifie la valeur de la case pour indiquer que la case a �t� vis�e
        this->cases[x][y] = 3;
        return false; // On retourne false pour indiquer que le tir a rat�
    }
}

// OPENGL

void Grille::afficheAll() {
	afficheGrille();
	// Affiche les objets dans la grille
    afficheCase();
}

// Dessine un carr�
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
// Carr� = Bateau
// Croix grise = Tir loup�
// Croix rouge = Tir sur un bateau

void Grille::dessineUnCarre(int posX, int posY, bool couleurClaire) {
    glBegin(GL_QUADS);

    if (couleurClaire) {
        glColor3f(0.9f, 0.9f, 1.0f);
    }
    else {
        glColor3f(0.7f, 0.7f, 0.9f);
    }

    // 4 sommets du carr�
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

void Grille::dessineCroix(int posX, int posY, bool touche) {
    glBegin(GL_QUADS);

    if (touche) {
        glColor3f(1.0f, 0.4f, 0.4f);
    }
    else {
        glColor3f(0.7f, 0.7f, 0.7f);
    }

    // 4 sommets du carr�
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
    // on v�rifie que les cases existent
    if (cases.size() > 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                // Juste un bateau
                if (cases[i][j] == 1) {
                    dessineUnCarre(i, j, false);
                }
                // Juste un tir loup�
                else if (cases[i][j] == 3) {
                    dessineCroix(i, j, false);
                }
                // Un tir r�ussi
                else if (cases[i][j] == 2) {
                    dessineCroix(i, j, true);
                    dessineUnCarre(i, j, false);
                }
            }
        }
    }    
}