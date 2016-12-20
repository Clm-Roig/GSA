// Programme principal du projet COAL
#include <stdlib.h>
#include <stdio.h>

// #include "src/BDD.c"
#include "src/ReconnaissanceV.c"


int main() {
    /* ---- TESTS BDD (Matthieu) ---- */
    /* setDatePesee(5,"09/07/1995");

    /* ---- TESTS ReconnaissanceV(Clément) ---- */
    FILE* fichier = fopen("data/images_aliments/bird.bmp","rb");
    ImageBMP* imBMP = initImageBMP(fichier);

    int res = unifierFond(imBMP);
    printf("\nRes : %d",res);

    return 0;
}
