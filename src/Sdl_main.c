#include "Sdl_main.h"

int main(int argc,char* args[]) {
	// Affichage de différentes fenetres
	/*
	init();

	menu();
	SDL_Delay(3000);
	peser();
	SDL_Delay(1000);
	stock();
	SDL_Delay(3000);

	cleanup();
	*/

	// Tests Clément
	time_t secondes;
	time(&secondes);
	struct tm* temps = localtime(&secondes);
	printf("%s",asctime(temps));

	return 0;
}
