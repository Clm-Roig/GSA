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


// ---- FONCTIONS ---- //

/**
    @brief renvoie le tableau des tuples : idAliment, dureeAvantPeremption, idPesee
    Si limite est supérieur au nombre de pesées, on renvoie toutes les pesées ordonnées.
    Si limite est inférieure au nombre de pesées, on renvoie des idAl,duree,idPes = 0
    @param int limite, le nombre d'id d'aliments à charger
    @return long int**, le tableau [i] => [idAliment, dureeAvPeremtpion, idPesee] (cases 0,1,2)
*/
long int** getTabIdDureeAvantPer(int limite);

#endif
