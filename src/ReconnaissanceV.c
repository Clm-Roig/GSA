#include "ReconnaissanceV.h"
// ---- FONCTIONS ---- //

int unifierFond(ImageBMP* image) {
    int res = 0;

    // Moyennes
    float moyenneR = 0;
    float moyenneG = 0;
    float moyenneB = 0;

    // Parcours de tous les pixels
    int i = 0;
    for(i; i < (image->taille_image) +20 ; i++) {
            /*
        moyenneR += getRCoul(image->couleurs[i]);
        moyenneG += getGCoul(image->couleurs[i]);
        moyenneB += getBCoul(image->couleurs[i]);
        */
    }

    moyenneR = moyenneR / (image->taille_image);
    moyenneG = moyenneG / (image->taille_image);
    moyenneB = moyenneB / (image->taille_image);

    printf("Rouge : %f",moyenneR);
    printf("\nVert : %f",moyenneG);
    printf("\nBleu : %f",moyenneB);

    return res;
}


Couleur* couleurDominante(ImageBMP* image) {

}


int rechercheAliment(Couleur* coul) {
    int res = 0;
    return res;
}


int* IdAlimentsDeCouleur(Couleur* coul) {

}


