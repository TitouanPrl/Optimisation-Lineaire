/*!
 *  \file code.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 28 March 2023 - 14:36:16
 *
 *  \brief Corps des fonctions
 *
 *
 */

#include "code.h"


/*!
 *  \fn void tabInit(float** tab, int lys, int rose, int jonquilles, int lys1, int rose1, int jonq1, int prix1, int lys2, int rose2, int jonq2, int prix2)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 12:13:34
 *  \brief Permet d'initialiser le tableau représentant le problème du fleuriste à l'étape 0
 *  \remarks Les paramètres représentent les données du problème
 */
void tabInit(float **tab, int lys, int rose, int jonquilles, int lys1, int rose1, int jonq1, int prix1, int lys2, int rose2, int jonq2, int prix2)
{
   /* Ligne d'en tête */
   tab[0][1] = 0; /* x1 */
   tab[0][2] = 1; /* x2 */
   tab[0][3] = 2; /* y1 */
   tab[0][4] = 3; /* y2 */
   tab[0][5] = 4; /* y3 */

   /* Première ligne : f */
   tab[1][1] = prix1;
   tab[1][2] = prix2;
   tab[1][3] = 0;
   tab[1][4] = 0;
   tab[1][5] = 0;
   tab[1][6] = 0;

   /* Deuxième ligne : y1 */
   tab[2][0] = 2;
   tab[2][1] = lys1;
   tab[2][2] = lys2;
   tab[2][3] = 1;
   tab[2][4] = 0;
   tab[2][5] = 0;
   tab[2][6] = lys;

   /* Troisième ligne : y2 */
   tab[3][0] = 3;
   tab[3][1] = rose1;
   tab[3][2] = rose2;
   tab[3][3] = 0;
   tab[3][4] = 1;
   tab[3][5] = 0;
   tab[3][6] = rose;

   /* Quatrième ligne : y3 */
   tab[4][0] = 4;
   tab[4][1] = jonq1;
   tab[4][2] = jonq2;
   tab[4][3] = 0;
   tab[4][4] = 0;
   tab[4][5] = 1;
   tab[4][6] = jonquilles;
}

/*!
 *  \fn void afficherTab(float** tab, int hauteur, int largeur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 12:21:58
 *  \brief affiche un tableau
 *  \param tab le tableau à afficher
 *  \param hauteur la hauteur du tableau
 *  \param largeur la largeur du tableau
 */
void afficherTab(float **tab, int hauteur, int largeur)
{
   for (int i = 1; i < hauteur; i++)
   {
      for (int j = 1; j < largeur; j++)
      {
         printf("%d ", tab[j][i]);
      }
   }
}

/*!
 *  \fn int varEntrante(float** tab, int largeur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 12:30:18
 *  \brief Permet de définir la variable entrante
 *  \param tab le tableau à afficher
 *  \param largeur la largeur du tableau
 *  \return le numéro de colonne de la variable entrante
 */
int varEntrante(float **tab, int largeur)
{
   /* Déclaration des variables */
   int numCol;
   int max;

   /* Initialisation */
   numCol = -1;
   max = 0;

   /* On check toutes les colonnes */
   for (int i = 1; i < largeur - 1; i++)
   {
      if (tab[1][i] > max)
      {
         max = tab[1][i];
         numCol = i;
      }
   }

   return (numCol);
}

/*!
 *  \fn int varEntrante(float** tab, int hauteur, int varIn)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 12:30:18
 *  \brief Permet de définir la variable sortante
 *  \param tab le tableau à afficher
 *  \param hauteur la hauteur du tableau
 *  \param varIn colonne de la variable entrante
 *  \return le numéro de ligne de la variable sortante
 */
int varSortante(float **tab, int hauteur, int varIn)
{
   /* Déclaration des variables */
   int numL;
   int ratioMin;

   /* Initialisation */
   numL = -1;
   ratioMin = tab[2][6] / tab[2][varIn];

   /* On check toutes les lignes */
   for (int i = 3; i < hauteur; i++)
   {
      if ((tab[i][6] / tab[i][varIn] < ratioMin) && (tab[i][6] / tab[i][varIn] > 0))
      {
         ratioMin = tab[i][6] / tab[i][varIn];
         numL = i;
      }
   }

   return (numL);
}

/*!
 *  \fn void entreeVar(float** tab, int varOut, float pivot, int varIn)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 15:17:43
 *  \brief Passe la variable entrante en base
 *  \param tab le tableau du problème
 *  \param varOut la ligne de la variable sortante
 *  \param pivot valeur du pivot
 *  \param largeur largeur du tableau
 *  \param varIn colonne de la variable entrante
 */
void entreeVar(float **tab, int varOut, float pivot, int largeur, int varIn)
{
   /* On met l'en-tête */
   tab[varOut][0] = tab[0][varIn];

   for (int j = 1; j < largeur; j++)
   {
      tab[varOut][j] = tab[varOut][j] / pivot;
   }
}

/* Combinaison linéaire sur la ligne de f lors de l'entrée en base de la variable */
void combiLin(float **tab, int ligne, int varOut, int varIn, int largeur)
{
   for (int j = 1; j < largeur; j++)
   {
      tab[ligne][j] = tab[ligne][j] - tab[ligne][varIn] * tab[varOut][j];
   }
}