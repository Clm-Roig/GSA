#ifndef DEF_Stock
#define DEF_Stock

// EN-TETE Stock.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


// ---- CONSTANTES ---- //

// ---- FONCTIONS ---- //

/**
    @brief renvoie le tableau des ids d'aliments ordonné par leur date de Peremption
    @param int limite, le nombre d'id d'aliments à charger
    @return int**, le tableau [id => durée Péremption]
*/
int** getTabIdDureePeremption(int limite);



#endif
