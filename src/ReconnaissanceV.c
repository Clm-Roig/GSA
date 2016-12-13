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
    fseek(image,0,0);
    return enTete;
}

int getLargeurBMP(FILE* image) {
    unsigned char* enTete = getEnTete(image);
    // Pas la peine d'aller chercher plus loin que l'octet 19, la largeur ne dépassera jamais 4096 pixels (16^3)
    int largeur = enTete[18] + 16*16*enTete[19];
    return largeur;
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
    Couleur *donnees[getTailleFichier(image)];
    unsigned char octet;

    // g et b nous permettront de savoir quel composante de couleur (G ou B) on a déjà stocké pour la couleur en cours.
    // Attention : pour chaque pixel, les composantes sont stockées à l'envers en Bitmap (BGR)
    int g=0;
    int b=0;

    // Offset contiendra le nombre octet ajouté à chaque ligne pour compléter
    // celle-ci de manire à ce que ce soit un multiple de 4
    int offset = getLargeurBMP(image)%4;

    // On se positionne au début des couleurs (octet 54)
    fseek(image,54,SEEK_SET);

    if(offset == 0) {
        // On récupère tout, aucun octet ajouté pour compléter
        // TODO : arrêter le while quand on a tout lu
        // TODO : tableau/pointeur de couleur ?
        int i=1;
        while(i < 25) {
            // TODO : coul doit être déclaré 1 fois sur 3
            fread(&octet,sizeof(octet),1,image);
            Couleur* coul = initCouleur();
            if(b==0) {
                setBCoul((int)octet,coul);
                b=1;
            }
            else if(g==0) {
                setGCoul((int)octet,coul);
                g=1;
            }
            else {
                setRCoul((int)octet,coul);
                g=0;
                b=0;
                printf("octet : %d\n",octet);
                printf("[%d %d %d] ",getRCoul(coul),getGCoul(coul),getBCoul(coul));
                donnees[i] = coul;
            }
            i++;
        }
    }
    else {
   /*     while (octet != EOF) {
            if (){
                i++
            }
            else {

            }
        }
   */ }
    return &donnees;
}

int unifierFond(FILE* image) {
    return 0;
}
