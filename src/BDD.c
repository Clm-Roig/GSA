/* Fonctions permettant l'écriture et la lecture des données dans /data */ 
#include "BDD.h"

/* ----- FONCTIONS ----- */

/* Ouverture */
FILE* ouvrirFichier(char * cheminFichier){
	FILE* fichier = NULL;
    fichier = fopen(cheminFichier, "r+");
    assert(fichier != NULL);
    return fichier;
}

FILE* ouvrirFichierAliment(char * nomFichier){
	char * cheminFichier = strcat(CHEMIN_ALIMENTS,nomFichier);
	cheminFichier = strcat(cheminFichier,".txt");
	return ouvrirFichier(cheminFichier);
}

FILE* ouvrirFichierPesee(char * nomFichier){
	char * cheminFichier = strcat(CHEMIN_PESEES,nomFichier);
	cheminFichier = strcat(cheminFichier,".txt");
	return ouvrirFichier(cheminFichier);
}

FILE* ouvrirFichierImagesAliments(char * nomFichier){
	// TODO : vérifier extension fichier (jpg ? png ?)
	char * cheminFichier = strcat(CHEMIN_IMAGES_ALIMENTS,nomFichier);
	cheminFichier = strcat(cheminFichier,".jpg");
	return ouvrirFichier(cheminFichier);
}


int main() {
	return 0;
}
