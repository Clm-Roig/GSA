#include "Sdl_main.h"

int main(int argc,char* args[]) {
	// Affichage de différentes fenetres
/*	init();

	menu();
	SDL_Delay(3000);
	peser();
	SDL_Delay(1000);
	stock();
	SDL_Delay(3000);

	cleanup();
*/

	// Tests Clément
	FILE* fichier = fopen("data/pesees.txt","r");

	// Tests de BDD (Clément)
	printf("\n\nPrint général : %s",lireLigneParId(fichier,2));

	fclose(fichier);

	return 0;
}
