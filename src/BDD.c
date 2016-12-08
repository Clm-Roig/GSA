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
    if (idLu != id) {
        ligneLu = "ID introuvable";
    }
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
    return nomLu;
}

char* getCouleurAliment(int id) {
    FILE* fichier = fopen(CHEMIN_ALIMENTS,"r");
    char* ligneLu = NULL;
    char* CouleurLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");    // id
    strtok(NULL,";");       // nom
    CouleurLu = strtok(NULL,";");
    return CouleurLu;
}

// Lecture Pesees
char* getQuantitePesee(int id) {
    FILE* fichier = fopen(CHEMIN_PESEES,"r");
    char* ligneLu = NULL;
    char* QuantiteLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");            // id
    QuantiteLu = strtok(NULL,";");  // quantite
    return QuantiteLu;
}

char* getDescriptionPesee(int id) {
    FILE* fichier = fopen(CHEMIN_PESEES,"r");
    char* ligneLu = NULL;
    char* DescriptionLu;

    ligneLu = malloc(TAILLE_MAX_LIGNE*sizeof(char));
    ligneLu = lireLigneParId(fichier,id);

    strtok(ligneLu,";");    // id
    strtok(NULL,";");       // quantite
    DescriptionLu = strtok(NULL,";");   // description
    printf(DescriptionLu);
    return DescriptionLu;
}

char* getDatePesee(int id) {

}

char* getIdAlimentPesee(int id) {

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
    fseek(fichier,0,0);
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
    fseek(fichier,0,0);
    return 1;
}
