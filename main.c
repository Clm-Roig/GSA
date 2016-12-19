// Programme principal du projet COAL
#include <stdlib.h>
#include <stdio.h>

// #include "src/BDD.c"
#include "src/LecteurBMP.c"


int main() {
    /* ---- TESTS BDD (Matthieu) ---- */
   /* setDatePesee(5,"09/07/1995");

    /* ---- TESTS LecteurBMP(Clément) ---- */
    FILE* fichier = fopen("data/images_aliments/bird.bmp","rb");
    ImageBMP* imb = initImageBMP();
    getDonnees(fichier, imb);
    printf("\n\n%d",getRCoul(imb->couleurs[1]));

    return 0;
}
