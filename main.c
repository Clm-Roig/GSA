// Programme principal du projet COAL
#include <stdlib.h>
#include <stdio.h>

// #include "src/BDD.c"
#include "src/Interface.c"


int main() {
    /* ---- TESTS BDD (Matthieu) ---- */
    /* setDatePesee(5,"09/07/1995");

    /* ---- TESTS Interface(Clément) ---- */
    FILE* fichier = fopen("data/images_aliments/bird.bmp","rb");
    ImageBMP* imBMP = initImageBMP(fichier);

    Couleur* res = couleurDominante(imBMP);
    printf(toCharCouleur(res));

    printf("\n%d",estUni(imBMP));
    return 0;
}
