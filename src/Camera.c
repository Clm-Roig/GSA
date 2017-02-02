#include "Camera.h"

// ---- FONCTIONS ---- //

int prendrePhoto(char* idPesee) {
    // Pour plus d'infos :
    // https://www.raspberrypi.org/wp-content/uploads/2013/07/RaspiCam-Documentation.pdf

    // raspistill permet de prendre une photo
    // -n annule la preview de la photo
    // -t delai avant prise de la photo
    // -ex Exposition
    // -w et -h hauteur et largeur de 800pxls
    // -e spécifie l'encodage de la photo
    // -co contraste (de -100 à +100)
    // -rot rotation de l'image (0 à 360°)

    char* fonction = "raspistill -rot 180 -co 25 -ex night -t 3000 -w 800 -h 800 -e bmp -o ";

    char* chemin = malloc(200*sizeof(char));
    strcpy(chemin,CHEMIN_IMAGES_ALIMENTS);
    strcat(chemin,idPesee);
    char* extension = ".bmp";

    char* exec = malloc(200*sizeof(char));
    strcpy(exec,fonction);
    strcat(exec,"\"");
    strcat(exec,chemin);
    strcat(exec,extension);
    strcat(exec,"\"");

    system(exec);

    return 1;
}
