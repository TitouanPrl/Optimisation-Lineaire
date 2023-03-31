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
 *  \fn void diviserLigne(int** tab, int nbCol, int numLigne, int case)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 28 March 2023 - 15:32:10
 *  \brief
 *  \param
 */
void diviserLigne(int **tab, int nbCol, int numLigne, int case)
{
   for (int j = 1; j < nb_col - 1; j++)
   {
      tab[numLigne][j] =
   }
}

/*!
 *  \fn void tabInit(int** tab, int lys, int rose, int jonquilles, int lys1, int rose1, int jonq1, int prix1, int lys2, int rose2, int jonq2, int prix2)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 12:13:34
 *  \brief Permet d'initialiser le tableau représentant le problème du fleuriste à l'étape 0
 *  \remarks Les paramètres représentent les données du problème
 */
void tabInit(int **tab, int lys, int rose, int jonquilles, int lys1, int rose1, int jonq1, int prix1, int lys2, int rose2, int jonq2, int prix2)
{
   /* Première ligne : f */
   tab[0][0] = prix1;
   tab[0][1] = prix2;
   tab[0][2] = 0;
   tab[0][3] = 0;
   tab[0][4] = 0;
   tab[0][5] = 0;

   /* Deuxième ligne : y1 */
   tab[1][0] = lys1;
   tab[1][1] = lys2;
   tab[1][2] = 1;
   tab[1][3] = 0;
   tab[1][4] = 0;
   tab[1][5] = lys;

   /* Troisième ligne : y2 */
   tab[2][0] = rose1;
   tab[2][1] = rose2;
   tab[2][2] = 0;
   tab[2][3] = 1;
   tab[2][4] = 0;
   tab[2][5] = rose;

   /* Quatrième ligne : y3 */
   tab[3][0] = jonq1;
   tab[3][1] = jonq2;
   tab[3][2] = 0;
   tab[3][3] = 0;
   tab[3][4] = 1;
   tab[3][5] = jonquilles;

}

/*!
 *  \fn void afficherTab(int** tab, int hauteur, int largeur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 12:21:58
 *  \brief affiche un tableau
 *  \param tab le tableau à afficher
 *  \param hauteur la hauteur du tableau
 *  \param largeur la largeur du tableau
 */
void afficherTab(int** tab, int hauteur, int largeur) {
    for (int i = 0; i < hauteur; i++)
    {
      for (int j = 0; j < largeur; j++)
      {
         printf("%d ", tab[j][i]);
      }
      
    }
    
}

/*!
 *  \fn int varEntrante(int** tab, int hauteur, int large)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 12:30:18
 *  \brief Permet de définir la variable entrante
 *  \param tab le tableau à afficher
 *  \param largeur la largeur du tableau
 *  \return le numéro de colonne de la variable entrante
 */
int varEntrante(int** tab, int largeur) {
   /* Déclaration des variables */
   int numCol;
   int max;

   /* Initialisation */
   max = 0;

   for (int i = 0; i < largeur; i++)
   {
      if (tab[0][i] > max)
      {
         max = tab[0][i];
         numCol = i;
      }
      
   }
   
    return (numCol);
}