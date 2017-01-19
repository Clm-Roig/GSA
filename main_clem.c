#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/ReconnaissanceV.c"
#include "src/Couleur.c"
#include "src/BDD.c"
#include "src/ImageBMP.c"
#include "src/Camera.c"

int main() {
    // BOULOT MATTHIEU
	// Ouvrir la photo
		// => FILE* => initImageBMP() ImageBMP (img)
	FILE* fichier = fopen("data/images_aliments/aubergine.bmp","rb");
	ImageBMP* img = initImageBMP(fichier);
	// L'analyser (couleurDominanteHorsFond)
		// => Couleur* blanc = initCouleurAvecParam(255,255,255)
		// => coul = couleurDominanteHorsFond(img,blanc)
	Couleur* blanc = initCouleurAvecParam(255,255,255);
	Couleur* coulDom = couleurDominanteHorsFond(img,blanc);

	fclose(fichier);

		// => sauver en BDD ecrireDonneesAliment(.....)
	ecrireDonneesAliment("aubergine",coulDom,0);

	// Renommer la photo
		// => rename sur FILE* (ou à la main)
	char* nvNom = malloc(30*sizeof(char));
	strcat(nvNom,"data/images_aliments/")
		
	char* id = NULL;
	sprintf(id, "%d", getIdMax("aliments"));
		
	strcat(nvNom,id);
	strcat(nvNom,".bmp");
	
	rename("data/images_aliments/aubergine.bmp",nvNom);

    // Si tu as le temps, cherche aussi les durées de péremption moyennes pour chaque aliment + ajoutes-en d'autres
	
    return 0;
}
