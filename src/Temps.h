#ifndef DEF_Temps
#define DEF_Temps

// EN-TETE Temps.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ---- CONSTANTES ---- //

// ---- FONCTIONS ---- //
/**
    @brief converti une string en structure tm
    @param char* str, la chaine à convertir
    @return struct tm, la structure de temps obtenue
*/
struct tm strToTm(char* str);
