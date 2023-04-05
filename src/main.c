/*! 
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 28 March 2023 - 14:37:53
 *
 *  \brief Programme principal permettant d'implémenter la méthode des tableaux pour l'optimisation linéaire
 *
 *
 */

#include "code.h"

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 28 March 2023 - 14:38:37
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres 
 *  \return 0 si tout s'est bien passé
 */
int main (int argc, char** argv) {

    /* ==== Problème basé sur l'énnoncé du TD1 1.2 ==== */

    /* Initialisation des variables */
    int varIn; /* Le numéro de colonne de la variable entrante */
    int varOut; /* Le numéro de ligne de la variable sortante */
    float pivot; /* Le pivot pour rentrer la variable */

    /* Initialisation du couple cherché */

    int a; /* Nb de premiers bouquets */
    int b; /* Nb de deuxièmes bouquets */
    int recetteMax; /* Recette max que l'on peut avoir avec les stocks disponibles */

    a = 0;
    b = 0;

    /* ---- On pose le problème ---- */

    /* Stocks totaux */
    int lys = 50;
    int rose = 80;
    int jonquilles = 80;

    /* Compo bouquet 1 */
    int lys1 = 10;
    int rose1 = 10;
    int jonq1 = 20;
    int prix1 = 40;

    /* Compo bouquet 2 */
    int lys2 = 10;
    int rose2 = 20;
    int jonq2 = 10;
    int prix2 = 50;

    /* Création du tableau */
    float tab[5][7]; /* 4 lignes 6 colonnes + les en-têtes */

    /* Initialisation du tableau modélisant le problème */
    tabInit(tab, lys, rose, jonquilles, lys1, rose1, jonq1, prix1, lys2, rose2, jonq2, prix2);

    /* Affichage du tableau */
    afficherTab(tab, 5, 7);

    /* On trouve la variable entrante */
    varIn = varEntrante(tab, 7);

    /* On trouve la variable sortante */
    varOut = varEntrante(tab, 5, varIn);

    /* On trouve le pivot */
    pivot = tab[varOut][varIn];

    /* On passe la variable entrante en base */
    entreeVar(tab, varOut, pivot, 7, varIn); 

    /* Combinaison linéaire sur les lignes pour obtenir des 0 dans la colonne */
    for (int i = 0; i < 5; i++)
    {
        /* On n'applique pas la combinaison linéaire sur la ligne de la var sortante */
        if (i != varOut)
        {
            combiLin(tab, i, varOut, varIn, 7);
        }
        
    }

    /* On fait la boucle pour trouver a et b s'ils sont en base */
    for (int i = 0; i < 5; i++)
    {
        /* On trouve a */
        if (tab[i][0] == 0)
        {
            a = tab[i][6];
        }

        /* On trouve b */
        if (tab[i][0] == 1)
        {
            b = tab[i][6];
        }        
        
    }
    

    /* On lit la recette max */
    recetteMax = -tab[0][5];
    

    /* On affiche la valeur max et le couple de valeur pour lequel il est atteint */
    printf("Valeur max : %f \n", recetteMax);
    printf("Optimum : (%f;%f) \n", /*val x1 val x2*/);
        

     return (EXIT_SUCCESS);
}
