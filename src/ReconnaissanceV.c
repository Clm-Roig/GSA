#include "ReconnaissanceV.h"

Couleur* getDonnees(FILE* image) {
    Couleur* couleurs = NULL;

    return couleurs;
}

char* getEnTete(FILE* image) {
    char* enTete = malloc(54*sizeof(char));
    unsigned char octet;

    // L'en-tête d'un fichier Bitmap fait 54 octets
    int i;
    for (i=0 ; i < 54 ; i++) {
        fread(&octet,sizeof(octet),1,image);
        enTete[i] = octet;
    }
    return enTete;
}

int formatLargeurBMP(FILE* image) {

    return 0;
}

int unifierFond(FILE* image) {
    return 0;
}
