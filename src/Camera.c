#include "Camera.h"

// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "data/images_aliments/";

// ---- FONCTIONS ---- //

int demarrerCam() {
    return 0;
}

int prendrePhoto(char* idPesee) {
    char* fonction = "raspistill -o ";
    char* chemin = malloc(50*sizeof(char));
    strcat(chemin,CHEMIN_IMAGES_ALIMENTS);
    strcat(chemin,idPesee);
    char* format = ".bmp";

    char* exec = malloc(100*sizeof(char));
    strcat(exec,fonction);
    strcat(exec,"\"");
    strcat(exec,chemin);
    strcat(exec,format);
    strcat(exec,"\"");

    system(exec);

    return 1;
}
