#include "LecteurBMP.h"

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

    // Offset contiendra le nombre octet ajouté à chaque ligne pour compléter
    // celle-ci de manière à ce que ce soit un multiple de 4
    int offset = getLargeurBMP(image)%4;

    // On se positionne au début des couleurs (octet 54)
    fseek(image,54,SEEK_SET);

    if(offset == 0) {
        // On récupère tout, aucun octet ajouté pour compléter
        // Attention : pour chaque pixel, les composantes sont stockées à l'envers en Bitmap (BGR)
        // TODO : arrêter le while quand on a tout lu
        // TODO : tableau/pointeur de couleur ?
        int i=1;
        while(i < 25) {
            Couleur* coul = initCouleur();

            fread(&octet,sizeof(octet),1,image);
            setBCoul((int)octet,coul);
            fread(&octet,sizeof(octet),1,image);
            setGCoul((int)octet,coul);
            fread(&octet,sizeof(octet),1,image);
            setRCoul((int)octet,coul);

            printf("octet : %d\n",octet);
            printf("[%d %d %d] ",getRCoul(coul),getGCoul(coul),getBCoul(coul));
            donnees[i] = coul;
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
