#ifndef DEF_Stock
#define DEF_Stock

// EN-TETE Stock.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "BDD.h"


// ---- CONSTANTES ---- //

// ---- Outils ---- //
/**
    @brief classe un tableau d'entiers
    @param int* tab, le tableau à classer
    @param int taille, la taille du tableau
    @return int*, le tableau classé
*/
int* sortTab(int* tab,int taille);


// ---- FONCTIONS ---- //

/**
    @brief renvoie le tableau des ids de pesées ordonné par leur durée avant Peremption (en secondes)
    @param int limite, le nombre d'id d'aliments à charger
    @return long int**, le tableau [id de la pesée => durée avant Péremption]
*/
long int** getTabIdDureeAvantPer(int limite);




#endif
