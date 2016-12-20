// Programme principal du projet COAL
#include <stdlib.h>
#include <stdio.h>

// #include "src/BDD.c"
#include "src/ReconnaissanceV.c"


int main() {
    /* ---- TESTS BDD (Matthieu) ---- */
    /* setDatePesee(5,"09/07/1995");

    /* ---- TESTS ReconnaissanceV(Clément) ---- */
    FILE* fichier = fopen("data/images_aliments/sample2.bmp","rb");
    ImageBMP* imBMP = initImageBMP(fichier);
    unifierFond(imBMP);

    return 0;
}
