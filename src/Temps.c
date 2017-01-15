#include "Temps.h"

// ---- CONSTANTES ---- //

// ---- FONCTIONS ---- //
struct tm* strToTm(char* str) {
    // str de la forme "Sun Feb 27 21:39:40 2011"
    // Recopie de la chaine pour pouvoir la modifier
    char* str2 = strdup(str);

    char* jourSemaine = strtok(str2," ");
    char* mois = strtok(NULL," ");
    char* jour = strtok(NULL," ");
    char* heure = strtok(NULL," ");
    char* annee = strtok(NULL," ");

    // Conversion dans une struct tm
    struct tm temps;
    temps.tm_mday = atoi(jour);

    return &temps;
}
