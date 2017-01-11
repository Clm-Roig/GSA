#include <stdio.h>
#include <stdlib.h>

#include "src/ReconnaissanceV.c"
#include "src/Couleur.c"
#include "src/BDD.c"
#include "src/ImageBMP.c"

int main() {
    Couleur* coul = initCouleur();
    setRCoul(25,coul);
    setGCoul(25,coul);
    setBCoul(25,coul);
    getIdAlimentParCouleur(coul,29);
    return 0;
}
