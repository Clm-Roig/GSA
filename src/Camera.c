#include "Camera.h"

// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "data/images_aliments/";

// ---- FONCTIONS ---- //

int demarrerCam() {
    return 0;
}

int prendrePhoto(char* idPesee) {
    // raspistill permet de prendre une photo
    // -e spécifie l'encodage de la photo
    char* fonction = "raspistill -e bmp -o ";
    char* chemin = malloc(50*sizeof(char));
    strcat(chemin,CHEMIN_IMAGES_ALIMENTS);
    strcat(chemin,idPesee);
    char* extension = ".bmp";

    char* exec = malloc(100*sizeof(char));
    strcat(exec,fonction);
    strcat(exec,"\"");
    strcat(exec,chemin);
    strcat(exec,extension);
    strcat(exec,"\"");

    system(exec);

    return 1;
}
