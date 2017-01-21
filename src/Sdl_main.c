#include "Sdl_main.h"

int main(int argc,char* args[]) {
/*
	int loop = 1;
	int page = 1;

	// Affichage de différentes fenetres
	init();

	while(loop==1){
		if(page==1){
			page = menu();
		}
		else if(page==2){
			page = peser();
		}
		else if(page==3){
			page = stock();
		}
		else if(page==0){
			loop = 0;
		}

	}

	cleanup();
*/

	FILE* fichier = fopen("data/images_aliments/tomate.bmp","rb");
	ImageBMP* img = initImageBMP(fichier);
	// L'analyser (couleurDominanteHorsFond)
		// => Couleur* blanc = initCouleurAvecParam(255,255,255)
		// => coul = couleurDominanteHorsFond(img,blanc)
	Couleur* blanc = initCouleurAvecParam(255,255,255);
	Couleur* coulDom = couleurDominanteHorsFond(img,blanc);

	fclose(fichier);

	// => sauver en BDD ecrireDonneesAliment(.....)
	ecrireDonneeAliment("tomate",coulDom,0);

	// Renommer la photo
		// => rename sur FILE* (ou à la main)
	char* nvNom = malloc(50*sizeof(char));
	strcpy(nvNom,"data/images_aliments/");

	char* id = malloc(4*sizeof(char));
	sprintf(id, "%d", getIdMax("aliments"));

	strcat(nvNom,id);
	strcat(nvNom,".bmp");

	rename("data/images_aliments/tomate.bmp",nvNom);

	return 0;
}
