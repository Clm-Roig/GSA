#include "Stock.h"

// ---- Fonctions ---- //

char** getTabIdDureeAvantPer(int limite) {
    // Pour chauqe ligne, on stocke id=>DureeAvantPeremption
    int resTab[limite][2];
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

    // Récupèration des durées de péremption de chaque aliment pesé
    long int tabDureePer[compteurTuples];
    for(i=0; i < compteurTuples ;i++) {
        // Pour chaque pesée, on récupère l'id de l'aliment pesée puis sa durée de péremption
        // La durée est stockée en jours, on la passe en secondes (1jour=86400sec)

        // ça ok
        char* test = getIdAlimentPesee(atoi(tabId[i]));
        printf("\n%s",test);

        // à débugguer
        long int duree = (long int)getDureePeremptionAliment(getIdAlimentPesee(tabId[i]));
        tabDureePer[i] = 86400*duree;
    }

    //////
        printf("\n\nPrintf du tableau");
        for(i=0; i < compteurTuples ;i++) {
            printf("\n%ld",tabDureePer[i]);
        }
    //////


    // Calcul de la durée restante avant péremption
/*    char resTabFull[compteurTuples][compteurTuples];
    for(i=0; i < compteurTuples ;i++) {
        resTabFull[i] = {tabId[i],  };
    }


    char* date = NULL;
    long int dateInt;
    printf("\n\nPrintf en date converti");
    for(i=0; i < compteurTuples ;i++) {
        date = tabDates[i];
        dateInt = atol(date);
        printf("\n%s",ctime(&dateInt));
    }
*/



}
