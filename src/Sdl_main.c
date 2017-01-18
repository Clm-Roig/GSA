#include "Sdl_main.h"

int main(int argc,char* args[]) {


	// Affichage de différentes fenetres
	init();


	menu();

	cleanup();

	// Tests Clément
	FILE* fichier = fopen("data/pesees.txt","r");

	fclose(fichier);

	return 0;
}
