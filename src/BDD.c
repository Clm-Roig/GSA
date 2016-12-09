#include "BDD.h"

// ---- LECTURE ---- //
int nbLignesFichier(FILE* fichier) {
    int nbLignes = 0;
    char* a = NULL;
    a = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    while(fgets(a, TAILLE_MAX_LIGNE, fichier) != NULL) {
        nbLignes++;
    }
    fseek(fichier,0,0);
    return nbLignes;
}

char* lireLigne(FILE* fichier, int n) {
    char* res = NULL;
    res = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    int max = nbLignesFichier(fichier);
    // On cherche la ligne correspondante
    if (fichier && n <= max) {
        while(n>0) {
            fgets(res,TAILLE_MAX_LIGNE,fichier);
            n--;
        }
    }
    fseek(fichier,0,0);
    return res;
}

int getIdMax(char* type) {
    assert(type != NULL);
    const char* chemin = NULL;
    if (strcmp(type,"aliments") == 0) {
        chemin = CHEMIN_ALIMENTS;
    }
    else if (strcmp(type,"pesees") == 0) {
        chemin = CHEMIN_PESEES;
    }
    else {
        return -1;
    }
    FILE* fichier = fopen(chemin,"r+");
    assert(fichier != NULL);
    int nbLignes = nbLignesFichier(fichier);
    char* ligne = lireLigne(fichier,nbLignes);
    int idMax = atoi(strtok(ligne,";"));
    fseek(fichier,0,0);
    return idMax;
}

char* lireLigneParId(FILE* fichier, int id) {
    char* ligneLu = NULL;
    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    int idLu;
    int max = nbLignesFichier(fichier);
    fseek(fichier,0,0);
    // On cherche la ligne correspondante
    if (fichier) {
        int n = 0;
        fseek(fichier,0,0);
        while(n <= max && idLu != id) {
            ligneLu = lireLigne(fichier,n);
            idLu = atoi(strtok(lireLigne(fichier,n),";"));
            n++;
        }
    }
    assert(idLu == id);

    fseek(fichier,0,0);
    return ligneLu;
}

// Lecture Aliments
char* getNomAliment(int id) {
    FILE* fichier = fopen(CHEMIN_ALIMENTS,"r");
    char* ligneLu = NULL;
    char* nomLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    nomLu = malloc(30*sizeof(char));

    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");        // id
    nomLu = strtok(NULL,";");   // nom
    fclose(fichier);
    return nomLu;
}

char* getCouleurAliment(int id) {
    FILE* fichier = fopen(CHEMIN_ALIMENTS,"r");
    char* ligneLu = NULL;
    char* couleurLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");    // id
    strtok(NULL,";");       // nom
    couleurLu = strtok(NULL,";");
    fclose(fichier);
    return couleurLu;
}

char* getIdAlimentParCouleur(char* couleur, int precision) {
    FILE* fichier = fopen(CHEMIN_ALIMENTS,"r");
    char* listeIds = NULL;
    listeIds = malloc(nbLignesFichier(fichier)*TAILLE_MAX_LIGNE*sizeof(char));
    char* ligneLu = NULL;
    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));

    int nbLignes = nbLignesFichier(fichier);
    int idLu;
    char* couleurLu = malloc(12*sizeof(char));

    int i=2;

    while (i<=nbLignes) {
        ligneLu = lireLigne(fichier,i);
        idLu = strtok(ligneLu,";");
        couleurLu = getCouleurAliment(idLu);
//TODO : à finir, nécessite Couleur.c

    }

}

// Lecture Pesees
char* getQuantitePesee(int id) {
    FILE* fichier = fopen(CHEMIN_PESEES,"r");
    char* ligneLu = NULL;
    char* quantiteLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");            // id
    quantiteLu = strtok(NULL,";");  // quantite
    fclose(fichier);
    return quantiteLu;
}

char* getDescriptionPesee(int id) {
    FILE* fichier = fopen(CHEMIN_PESEES,"r");
    char* ligneLu = NULL;
    char* descriptionLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");    // id
    strtok(NULL,";");       // quantite
    descriptionLu = strtok(NULL,";");   // description
    fclose(fichier);
    return descriptionLu;
}

char* getDatePesee(int id) {
    FILE* fichier = fopen(CHEMIN_PESEES,"r");
    char* ligneLu = NULL;
    char* dateLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");    // id
    strtok(NULL,";");       // quantite
    strtok(NULL,";");       // description
    dateLu = strtok(NULL,";");   // date
    fclose(fichier);
    return dateLu;
}

char* getIdAlimentPesee(int id) {
    FILE* fichier = fopen(CHEMIN_PESEES,"r");
    char* ligneLu = NULL;
    char* idAlimentLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");    // id
    strtok(NULL,";");       // quantite
    strtok(NULL,";");       // description
    strtok(NULL,";");       // date
    idAlimentLu = strtok(NULL,";");   // id_aliment
    fclose(fichier);
    return idAlimentLu;
}

// ---- ECRITURE ---- //
int ecrireDonneeAliment(char* nom, char* couleur) {
    FILE* fichier = fopen(CHEMIN_ALIMENTS,"r+");
    assert(fichier != NULL);
    fseek(fichier,0,SEEK_END);

    // Saut de ligne avant insertion et formatage des données
    char buffer[TAILLE_MAX_LIGNE]="\n";

    // Obtention de l'id du nouvel aliment
    int id = getIdMax("aliments") + 1;
    char *idchar = NULL;
    idchar = malloc(10*sizeof(char));
    sprintf(idchar,"%d",id);

    strcat(buffer,idchar);
    strcat(buffer,";");
    strcat(buffer,nom);
    strcat(buffer,";");
    strcat(buffer,couleur);
    strcat(buffer,";");

    fprintf(fichier,buffer);
    fclose(fichier);
    return 1;
}

int ecrireDonneePesee(int quantite,char* description,char* date,int id_aliment) {
    FILE* fichier = fopen(CHEMIN_PESEES,"r+");

    // Contrôles
    assert(fichier != NULL);
    assert(id_aliment != NULL && id_aliment != "");
    assert(date != NULL && date != "");

    // Saut de ligne avant insertion et formatage des données
    char buffer[TAILLE_MAX_LIGNE]="\n";

    // Obtention de l'id de la nouvelle pesée
    int id = getIdMax("pesees") + 1;
    fseek(fichier,0,SEEK_END);
    char *idchar = NULL;
    idchar = malloc(10*sizeof(char));
    sprintf(idchar,"%d",id);

    // Conversion des données int en char
    char *quantite_char = NULL;
    quantite_char = malloc(100*sizeof(char));
    char *id_aliment_char = NULL;
    id_aliment_char = malloc(10*sizeof(char));
    sprintf(quantite_char,"%d",quantite);
    sprintf(id_aliment_char,"%d",id_aliment);

    // Ecriture dans le fichier (+ conversion des NULL en " ")
    strcat(buffer,idchar);
    strcat(buffer,";");

    if (quantite_char == "") {
         strcat(buffer," ");
    }
    else {
         strcat(buffer,quantite_char);
    }
    strcat(buffer,";");

    if (description == "") {
         strcat(buffer," ");
    }
    else {
         strcat(buffer,description);
    }

    strcat(buffer,";");
    strcat(buffer,date);
    strcat(buffer,";");
    strcat(buffer,id_aliment_char);

    fprintf(fichier,buffer);
    fclose(fichier);
    return 1;
}

// ---- SUPPRESSION ---- //
int supprimerDonneeAliment(int id){
    FILE* fichier = fopen(CHEMIN_ALIMENTS,"r+");

    // Obtention ligne à Supprimer
    char* ligneASupprimer = NULL;
    ligneASupprimer = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneASupprimer = lireLigneParId(fichier,id);

    FILE* fichierTemp = fopen(CHEMIN_ALIMENTS_TEMP,"a");

    // Recopie du fichier dans le fichier .tmp sauf la ligne à supprimer
    char* ligneLu = NULL;
    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    while(fgets(ligneLu, TAILLE_MAX_LIGNE, fichier) != NULL) {
        if(strcmp(ligneLu,ligneASupprimer)) {
            fprintf(fichierTemp,ligneLu);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    int res = 1;
    if(remove(CHEMIN_ALIMENTS) != 0 || rename(CHEMIN_ALIMENTS_TEMP,CHEMIN_ALIMENTS) != 0) {
        res = 0;
    }
    return res;
}

int supprimerDonneePesee(int id){
    FILE* fichier = fopen(CHEMIN_PESEES,"r+");

    // Obtention ligne à Supprimer
    char* ligneASupprimer = NULL;
    ligneASupprimer = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneASupprimer = lireLigneParId(fichier,id);

    FILE* fichierTemp = fopen(CHEMIN_PESEES_TEMP,"a");


    // Recopie du fichier dans le fichier .tmp sauf la ligne à supprimer
    char* ligneLu = NULL;
    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    while(fgets(ligneLu, TAILLE_MAX_LIGNE, fichier) != NULL) {
        if(strcmp(ligneLu,ligneASupprimer)) {
            fprintf(fichierTemp,ligneLu);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    int res = 1;
    if(remove(CHEMIN_PESEES) != 0 || rename(CHEMIN_PESEES_TEMP,CHEMIN_PESEES) != 0) {
        res = 0;
    }
    return res;
}
