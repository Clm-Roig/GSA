// Programme principal du projet COAL
#include <stdlib.h>
#include <stdio.h>

#include "src/BDD.c"


int main() {
    /* ---- TESTS Interface(Clément) ---- */
    Couleur* coul = initCouleur();
    setRCoul(3,coul);
    setGCoul(255,coul);
    setBCoul(147,coul);
    getIdAlimentParCouleur(coul,1);
    return 0;
}
