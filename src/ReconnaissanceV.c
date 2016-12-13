#include "ReconnaissanceV.h"

unsigned char* getEnTete(FILE* image) {
    unsigned char* enTete = malloc(54*sizeof(unsigned char));
    unsigned char octet;

    // L'en-tête d'un fichier Bitmap fait 54 octets
    int i;
    for (i=0 ; i < 54 ; i++) {
        fread(&octet,sizeof(octet),1,image);
        enTete[i] = octet;
    }

    return enTete;
}

//TODO : vérifier les 16*16 (pas bon)
int formatLargeurBMP(FILE* image) {
    unsigned char* enTete = getEnTete(image);
    // pas la peine d'aller chercher plus loin que l'octet 19, la largeur ne dépassera jamais 4096 pixels (16^3)
    int largeur = enTete[18] + 16*16*enTete[19];
    printf("%d",largeur);
    return (largeur%4==0);
}

long getTailleFichier(FILE* image) {
    unsigned char* enTete = getEnTete(image);
    unsigned char* inverseEnTete = malloc(4*sizeof(unsigned char));
    long a = enTete[2];
    long b = 16*16*enTete[3];
    long c = 16*16*16*16*enTete[4];
    long d = 16*16*16*16*16*16*enTete[5];
    long taille_fichier = a + b + c + d;
    return taille_fichier;
}

Couleur* getDonnees(FILE* image) {
    Couleur* donnees = NULL;
    donnees = malloc(getTailleFichier(image)*sizeof(Couleur));

    // On se positionne au début des couleurs
    fseek(image,54,SEEK_SET);
    int i;
    unsigned char octet;

    fread(&octet,sizeof(octet),1,image);
    printf("%d",octet);


    return donnees;
}

int unifierFond(FILE* image) {
    return 0;
}
