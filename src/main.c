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
 *  \date Tue 28 March 2023 - 14:38:36
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
    int tab[4][6]; /* 4 lignes 6 colonnes */

    /* Initialisation du tableau modélisant le problème */
    tabInit(tab, lys, rose, jonquilles, lys1, rose1, jonq1, prix1, lys2, rose2, jonq2, prix2);

    /* Affichage du tableau */
    afficherTab(tab, 4, 6);

    /* On trouve la variable entrante */
    varIn = varEntrante(tab, 6);

    /* On trouve la variable sortante */
    varOut = varEntrante(tab, 4, varIn);

    /* On trouve le pivot */
    pivot = tab[varOut][varIn];

    /* On passe la variable entrante en base */
    entreeVar(tab, varOut, pivot, 6);

    /* Combinaison linéaire sur les lignes pour obtenir des 0 dans la colonne */
    combiLinF(tab, varIn, varOut, 6);



     
    if (X)
    {
        Choisir J dans ...
        if (1 <= k <= floor(m) && a[k][j] > 0)
        {
            On choisit I dans ...
            tmp = z[i];
            z[i] = e[j];
            e[j] = z[i];
            diviserLigne(tab, numLigne, a[i][j]); /* Li <- Li / a[i][j]*/
            
            for (int k = 0; k < m + 1; k++)
            {
                if (k != i)
                {
                    soustraireLigne(tab, numLigne1, numLigne2, a[k][j]);
                }
                
            }
            
        }
        
    }
    

     return (EXIT_SUCCESS);
}
