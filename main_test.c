// Programme de test du projet COAL
#include <stdlib.h>
#include <stdio.h>

#include "src.BDD.c"
#include "src/Camera.c"
#include "src/Couleur.c"
#include "src/ReconnaissanceV.c"
#include "src/ImageBMP.c"

int main() {
    prendrePhoto("test");
    printf("\nPhoto prise !");
    FILE* fichier = fopen("data/images_aliments/test.bmp","rb");
    ImageBMP* img = initImageBMP(fichier);
    printf("\nCouleur Dominante : %s",toCharCouleur(couleurDominante(img)));
    return 0;
}
