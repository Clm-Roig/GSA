#include <stdio.h>
#include <stdlib.h>

#include "src/ReconnaissanceV.c"
#include "src/Couleur.c"
#include "src/BDD.c"
#include "src/ImageBMP.c"

int main() {
    FILE* fichier = fopen("data/pesees.txt","a");
    printf(getDatePesee(2));
    return 0;
}
