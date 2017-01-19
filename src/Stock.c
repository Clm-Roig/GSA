#include "Stock.h"

// ---- Outils ---- //
int* sortTab(int* tab,int taille) {

        
}

// ---- Fonctions ---- //

long int** getTabIdDureeAvantPer(int limite) {
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
        char* date = strtok(NULL,";"); // date
        tabDates[compteurTuples] = date;
        compteurTuples++;
    }

    // Récupèration des durées de péremption de chaque aliment pesé
    long int tabDureePer[compteurTuples];
    for(i=0; i < compteurTuples ;i++) {
        // Pour chaque pesée, on récupère l'id de l'aliment pesée puis sa durée de péremption
        // La durée est stockée en jours, on la passe en secondes (1jour=86400sec)
        char* idAlimentPese = getIdAlimentPesee(atoi(tabId[i]));
        int duree = getDureePeremptionAliment(atoi(idAlimentPese));
        tabDureePer[i] = 86400*duree;
    }

    // Calcul de la durée restante avant péremption
    long int** resTabFull[compteurTuples];
    long int now = (long int) time(NULL);

    for(i=0; i < compteurTuples ;i++) {
        // Sert à rien ici en soit, mais nécessaire pour strtol()
        char* ptr;
        long int dureePassee = now - strtol(tabDates[i],&ptr,10);
        long int dureeRestante = tabDureePer[i] - dureePassee;

        long int id = strtol(tabId[i],&ptr,10);
        long int tab[2] = {id,dureeRestante};
        resTabFull[i] = tab;
    }

    // resTabFull à débugguer TODO
    //////
        printf("\n\nPrintf du tableau full");
        for(i=0; i < compteurTuples ;i++) {
            printf("\n%ld %ld",resTabFull[i][0],resTabFull[i][1]);
        }
    //////



}
