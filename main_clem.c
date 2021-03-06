#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/ReconnaissanceV.c"
#include "src/Couleur.c"
#include "src/BDD.c"
#include "src/ImageBMP.c"
#include "src/Camera.c"

int main() {




    return 0;
}

void ajoutPhotoBDD(){
      // Ajout d'un aliment dans la BDD (changer nom du fichier .bmp � 3 endroits)
  FILE* fichier = fopen("data/images_aliments/peche.bmp","rb");
  ImageBMP* img = initImageBMP(fichier);

  // Analyse de l'image
  Couleur* blanc = initCouleurAvecParam(255,255,255);
  Couleur* coulDom = couleurDominanteHorsFond(img,blanc);

  fclose(fichier);

  // Sauver en BDD
  ecrireDonneeAliment("peche",coulDom,0);

  // Renommer la photo
  char* nvNom = malloc(50*sizeof(char));
  strcpy(nvNom,"data/images_aliments/");

  char* id = malloc(4*sizeof(char));
  sprintf(id, "%d", getIdMax("aliments"));

  strcat(nvNom,id);
  strcat(nvNom,".bmp");

  rename("data/images_aliments/peche.bmp",nvNom);

}
