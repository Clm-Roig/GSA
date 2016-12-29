#ifndef DEF_Interface
#define DEF_Interface

// EN-TETE Interface.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ---- CONSTANTES ---- //

// ---- FONCTIONS ---- //

/**
	@brief Affiche à l'écran n sauts de ligne
	@param int n, le nb de lignes à sauter
*/
void sautLignes(int n);

/**
	@brief Affiche le menu principal
*/
void afficherMenuPrincipal();

/**
    @brief Permet de saisir un entier, de le contrôler puis d'éventuellemnt l'enregistrer dans une variable
    @param int x, la variable dans laquelle on veut enregistrer l'entier saisi
    @return bool, 1 si la saisie s'est bien passée, sinon 0
*/
int saisirInt(int x);

/**
    @brief Permet de saisir un caractère, de le contrôler puis d'éventuellemnt l'enregistrer dans une variable
    @param char x, la variable dans laquelle on veut enregistrer le caractère saisi
    @return bool, 1 si la saisie s'est bien passée, sinon 0
*/
int saisirChar(char x);

/**
    @brief Permet de saisir une String, de la contrôler puis d'éventuellemnt l'enregistrer dans une variable
    @param char* x, la variable dans laquelle on veut enregistrer la String saisie
    @return bool, 1 si la saisie s'est bien passée, sinon 0
*/
int saisirSring(char* x);

#endif
