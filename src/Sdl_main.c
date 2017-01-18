#include "Sdl_main.h"

int main(int argc,char* args[]) {
	SDL_Event event;


	// Affichage de différentes fenetres
	init();

int loop = 1;
while(loop==1){
	int x = 0; int y = 0;
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_MOUSEBUTTONUP:
        	x = event.button.x;
            y = event.button.y;
            break;
    }
    if(x<=100){
    	loop= 0;
    }
    else{
    	menu();
    }
}


	/*menu();
	SDL_Delay(6000);
	peser();
	SDL_Delay(1000);
	stock();
	SDL_Delay(3000);*/

	cleanup();

	// Tests Clément
	FILE* fichier = fopen("data/pesees.txt","r");

	fclose(fichier);

	return 0;
}
