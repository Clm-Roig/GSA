#include "Camera.h"

// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "date/images_aliments";

// ---- FONCTIONS ---- //

int demarrerCam() {
  return 0;
}

int prendrePhoto(char* idPesee) {
  char* fonction = "raspistill -o";
  char* chemin = NULL;
  strcat(chemin,CHEMIN_IMAGES_ALIMENTS);
  strcat(chemin,idPesee);
  char* format = ".bmp";

  char* exec = malloc(100*sizeof(char));
  strcat(exec,fonction);
  strcat(exec,chemin);
  strcat(exec,format);

  //system(exec);
  printf("%s",exec);
  return 1;
}
