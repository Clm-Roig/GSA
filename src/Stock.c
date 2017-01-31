#include "Stock.h"

// ---- Fonctions ---- //
long int** getTabIdDureeAvantPer(int limite) {
    FILE* fichier = fopen(CHEMIN_PESEES,"r");
    int nbPesees = nbLignesFichier(fichier);

    // On récupère tous les ids et dates des pesees
    int i;
    int compteurTuples = 0;

    char* tabIdAl[nbPesees-1];
    char* tabDates[nbPesees-1];
    char* tabIdPes[nbPesees-1];

    for(i=2; i <= nbPesees ;i++){
        char* ligneLu = lireLigne(fichier,i);
        char* tok = strtok(ligneLu,";");

        tabIdPes[compteurTuples] = tok; // id pesée

        tok = strtok(NULL,";"); // quantité
        tok = strtok(NULL,";"); // description
        tok = strtok(NULL,";"); // date
        tabDates[compteurTuples] = tok;

        tok = strtok(NULL,";"); // id aliment
        tabIdAl[compteurTuples] = tok;

        compteurTuples++;
    }

    // Récupèration des durées de péremption de chaque aliment pesé
    long int tabDureePer[compteurTuples];
    for(i=0; i < compteurTuples ;i++) {
        // Pour chaque pesée, on récupère l'id de l'aliment pesée puis sa durée de péremption
        // La durée est stockée en jours, on la passe en secondes (1jour=86400sec)
        int duree = getDureePeremptionAliment(atoi(tabIdAl[i]));
        tabDureePer[i] = (long int)86400*duree;
    }

    // Calcul de la durée restante avant péremption + remplissage du tableau
    long int resTabFull[compteurTuples][3];
    long int now = (long int) time(NULL);

    for(i=0; i < compteurTuples ;i++) {
        // ptr sert à rien ici en soit, mais nécessaire pour strtol()
        char* ptr;
        long int dureePassee = now - strtol(tabDates[i],&ptr,10);
        long int dureeRestante = tabDureePer[i] - dureePassee;
        long int idAl = strtol(tabIdAl[i],&ptr,10);
        long int idPes = strtol(tabIdPes[i],&ptr,10);

        resTabFull[i][0] = idAl;
        resTabFull[i][1] = dureeRestante;
        resTabFull[i][2] = idPes;
    }

    // Classer le tableau par durée avant péremption
    int j;
    for (i = 0; i < compteurTuples; i++) {
        for (j = i + 1; j < compteurTuples; j++) {
            if(resTabFull[i][1] > resTabFull[j][1]) {
                long int idAl = resTabFull[i][0];
                long int duree =  resTabFull[i][1];
                long int idPes = resTabFull[i][2];

                resTabFull[i][0] = resTabFull[j][0];
                resTabFull[i][1] = resTabFull[j][1];
                resTabFull[i][2] = resTabFull[j][2];

                resTabFull[j][0] = idAl;
                resTabFull[j][1] = duree;
                resTabFull[j][2] = idPes;
            }
        }
    }

    // Allocation du tableau final
    long int **resTab = malloc(sizeof(*resTab)*limite);
    for (i = 0; i < limite; i++) {
        resTab[i] = malloc(sizeof(**resTab)*3);
    }

    // Remplissage du tableau final
    if(limite <= compteurTuples) {
        for (i = 0; i < limite; i++) {
            resTab[i][0] = resTabFull[i][0];
            resTab[i][1] = resTabFull[i][1];
            resTab[i][2] = resTabFull[i][2];
        }
    }
    // Il y avait moins de pesees que la limite, on remplit avec des 0
    else {
        for (i = 0; i < compteurTuples; i++) {
            resTab[i][0] = resTabFull[i][0];
            resTab[i][1] = resTabFull[i][1];
            resTab[i][2] = resTabFull[i][2];
        }
        for (i = compteurTuples; i < limite; i++) {
            resTab[i][0] = 0;
            resTab[i][1] = 0;
            resTab[i][2] = 0;
        }
    }

    return resTab;
}

/*
//////
    printf("\n\nPrintf du tableau");
    for(i=0; i < limite ;i++) {
        printf("\n%ld %ld",resTab[i][0],resTab[i][1]);
    }
//////
*/
