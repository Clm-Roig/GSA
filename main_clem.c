#include <stdio.h>
#include <stdlib.h>

#include "src/ReconnaissanceV.c"

int main() {
    Couleur* blanc = initCouleur();
    setRCoul(255,blanc);
    setGCoul(255,blanc);
    setBCoul(255,blanc);

    FILE* fichier = fopen("data/images_aliments/tomate.bmp","rb");
    ImageBMP* img = initImageBMP(fichier);
    printf("\nCouleur dominante : %s",toCharCouleur(couleurDominante(img)));
    printf("\nCouleur dominante hors fond : %s",toCharCouleur(couleurDominanteHorsFond(img,blanc)));

    fclose(fichier);
    return 0;
}
