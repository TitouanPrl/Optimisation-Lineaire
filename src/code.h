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

void diviserLigne(int** tab, int nbCol, int numLigne, int case);

#endif