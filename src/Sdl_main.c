#include "Sdl_main.h"

int main(int argc,char* args[]) {
	SDL_Event event;


	// Affichage de différentes fenetres
	init();



    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
        	menu();
            break;
    }


	menu();
	SDL_Delay(6000);
	peser();
	SDL_Delay(1000);
	stock();
	SDL_Delay(3000);

	cleanup();

	// Tests Clément
	FILE* fichier = fopen("data/pesees.txt","r");

	fclose(fichier);

	return 0;
}
