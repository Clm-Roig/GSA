#include "Camera.h"

int demarrerCam()
{
  return 0;
}

int prendrePhoto()
{
  system("raspistill -o CHEMIN_IMAGES_ALIMENTS/test.bmp");
  return 1;
}
