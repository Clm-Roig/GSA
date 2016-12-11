// Programme principal du projet COAL
#include <stdlib.h>
#include <stdio.h>

#include "src/ReconnaissanceV.c"

int main() {
    FILE* fichier = fopen("data/images_aliments/sample2.bmp","r");
    getEnTete(fichier);
    return 0;
}
