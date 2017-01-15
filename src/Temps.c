#include "Temps.h"

// ---- CONSTANTES ---- //

// ---- FONCTIONS ---- //
struct tm* strToTm(char* str) {
    // str de la forme "Sun Feb 27 21:39:40 2011"
    // Recopie de la chaine pour pouvoir la modifier (strtok)
    char* str2 = strdup(str);

    char* jourSemaine = strtok(str2," ");
    char* mois = strtok(NULL," ");
    char* jour = strtok(NULL," ");
    char* heure = strtok(NULL," ");
    char* annee = strtok(NULL," ");

    // Conversion dans une struct tm
    struct tm* temps;
    temps->tm_mday = atoi(jour);

    return temps;
}

int* parseHour(char* str) {
    // Recopie de la chaine pour pouvoir la modifier(strtok)
    char* str2 = strdup(str);

    int h = atoi(strtok(str2,":"));
    int m = atoi(strtok(NULL,":"));
    int s = atoi(strtok(NULL,":"));

    int* res = malloc(3*sizeof(int));
    res[0] = h;
    res[1] = m;
    res[2] = s;
    return res;
}

int wDayToInt(char* str) {
    int res=-1;

    if(strcmp(str,"Sat") == 0) res = 0;
    else if(strcmp(str,"Mon") == 0) res = 1;
    else if(strcmp(str,"Tue") == 0) res = 2;
    else if(strcmp(str,"Wed") == 0) res = 3;
    else if(strcmp(str,"Thu") == 0) res = 4;
    else if(strcmp(str,"Fri") == 0) res = 5;
    else if(strcmp(str,"Sat") == 0) res = 6;

    if (res == -1) {
        printf("Erreur wDayToInt : str pas au bon format.");
    }

    return res;
}

int monthToInt(char* str) {
    int res=-1;

    if(strcmp(str,"Jan") == 0) res = 0;
    else if(strcmp(str,"Feb") == 0) res = 1;
    else if(strcmp(str,"Mar") == 0) res = 2;
    else if(strcmp(str,"Apr") == 0) res = 3;
    else if(strcmp(str,"May") == 0) res = 4;
    else if(strcmp(str,"Jun") == 0) res = 5;
    else if(strcmp(str,"Jul") == 0) res = 6;
    else if(strcmp(str,"Aug") == 0) res = 7;
    else if(strcmp(str,"Sep") == 0) res = 8;
    else if(strcmp(str,"Oct") == 0) res = 9;
    else if(strcmp(str,"Nov") == 0) res = 10;
    else if(strcmp(str,"Dec") == 0) res = 11;

    if (res == -1) {
        printf("\nErreur monthToInt : paramètre pas au bon format.");
    }

    return res;
}

int yearToInt(char* str) {
    int res;
    res = atoi(str) - 1900;
    if (res <= 100) {
        printf("\nErreur yearToInt : année passée en paramètre incorrecte.");
    }
    return res;
}
