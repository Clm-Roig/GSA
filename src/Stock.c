#include "Stock.h"

// ---- Fonctions ---- //

int** getTabIdDureePeremption(int limite) {
    int resTab[limite][limite];
    FILE* fichier = fopen(CHEMIN_PESEES,"r");

    // On récupère tous les ids et dates des pesees
    int i;
    for(i=2; i < nbLignesFichier(fichier) ;i++){
        //int tabId[i] = strtok(lireLigne(fichier,1),";");
        printf(strtok(lireLigne(fichier,1),";"));
        int tabDate[i];
    }
}
