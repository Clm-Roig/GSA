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
    @brief converti une string au format "Sun Feb 27 21:39:40 2011" en structure tm. asctime() fait l'inverse
    @param char* str, la chaine à convertir
    @return struct tm*, l'adresse de la structure de temps obtenue
*/
struct tm* strToTm(char* str);

/**
    @brief parse une chaine d'heure (21:36:40 => 21h36 et 40s) en un tableau de int ([21,36,40])
    @param char* str, la chaine à convertir
    @return int*, le tableau d'entiers correspondant à l'heure
*/
int* parseHour(char* str);

/**
    @brief converti un jour de la semaine (format Mon/Tue/Wed...) en un int compris entre 0 et 6 (0 = dimanche)
    @param char* str, la chaine à convertir
    @return int, le jour de la semaine correspondant
*/
int wDayToInt(char* str);

/**
    @brief converti un mois (format Jan/Feb/Mar...) en un int compris entre 0 et 11 (0=janvier)
    @param char* str, la chaine à convertir
    @return int, le mois correspondant
*/
int monthToInt(char* str);

/**
    @brief converti une année (format 2015) en un int
    @param char* str, la chaine à convertir
    @return int, le nb d'années écoulées depuis 1900
*/
int yearToInt(char* str);

#endif
