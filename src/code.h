#ifndef __CODE_H
#define __CODE_H

/*! 
 *  \file code.h
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 28 March 2023 - 14:36:35
 *
 *  \brief Prototypes des fonctions
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include <string.h>
/*! 
 \def EXIT_SUCCESS
  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0
/*! 
 \def ERREUR_SAISIE
  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1
/*! 
 \def EXIT_FAIL
  Code d'erreur attestant qu'une erreur s'est produite dans l'exécution
*/
#define EXIT_FAIL -1
/*! 
 \def ERREUR
  Message affiché quand il y a une erreur
*/
#define ERREUR(message) fprintf(stderr, "%s\n", message)
/*! 
 \def TEST
  Message affiché pour faire des test
*/
#define TEST(message) printf("%s\n", message)

/*!
 *  \fn void tabInit(float** tab, int lys, int rose, int jonquilles, int lys1, int rose1, int jonq1, int prix1, int lys2, int rose2, int jonq2, int prix2)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 12:13:34
 *  \brief Permet d'initialiser le tableau représentant le problème du fleuriste à l'étape 0
 *  \remarks Les paramètres représentent les données du problème
 */
void tabInit(float **tab, int lys, int rose, int jonquilles, int lys1, int rose1, int jonq1, int prix1, int lys2, int rose2, int jonq2, int prix2);

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
void afficherTab(float **tab, int hauteur, int largeur);

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
int varEntrante(float **tab, int largeur);

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
int varSortante(float **tab, int hauteur, int varIn);

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
void entreeVar(float **tab, int varOut, float pivot, int largeur, int varIn);

/*!
 *  \fn void combiLinF(float** tab, int ligne, int varOut, int varIn, int largeur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 31 March 2023 - 15:39:09
 *  \brief Combinaison linéaire sur la ligne de f lors de l'entrée en base de la variable
 *  \param tab le tableau du problème
 *  \param ligne la ligne à modifier
 *  \param varOut la ligne de la variable sortante
 *  \param varIn colonne de la variable entrante
 *  \param largeur largeur du tableau
 */
void combiLin(float **tab, int ligne, int varOut, int varIn, int largeur);


#endif