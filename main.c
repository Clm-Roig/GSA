// Programme principal du projet COAL
#include <stdlib.h>
#include <stdio.h>

#include "src/LecteurBMP.c"

int main() {
    FILE* fichier = fopen("data/images_aliments/bird.bmp","r");
    Couleur * coul = getDonnees(fichier);
    return 0;
}
