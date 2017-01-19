#include "Stock.h"

// ---- Fonctions ---- //

char** getTabIdDureePeremption(int limite) {
    int resTab[limite][limite];
    FILE* fichier = fopen(CHEMIN_PESEES,"r");

    // On récupère tous les ids et dates des pesees
    int i;
    int compteurTuples = 0;
    char* tabId[nbLignesFichier(fichier)-1];
    char* tabDates[nbLignesFichier(fichier)-1];
    for(i=2; i <= nbLignesFichier(fichier) ;i++){
        tabId[compteurTuples] = strtok(lireLigne(fichier,i),";"); //id
        strtok(NULL,";"); // quantité
        strtok(NULL,";"); // description
        tabDates[compteurTuples] = strtok(NULL,";"); // date
        compteurTuples++;
    }

    printf("Printf du tableau");
    for(i=0; i < compteurTuples ;i++) {
        printf("\n%s",tabDates[i]);
    }

    // On convertit les dates de pesées en durée de péremption
    char* date;
    long int dateInt;
    for(i=0; i < compteurTuples ;i++) {
        
    }



    printf("\n\nPrintf en date converti");
    for(i=0; i < compteurTuples ;i++) {
        date = tabDates[i];
        dateInt = atol(date);
        printf("\n%s",ctime(&dateInt));
    }




}
