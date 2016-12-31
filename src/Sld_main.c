#include "Sdl_main.h"



int main2(int argc,char* args[]) {
			init();

			menu();
			SDL_Delay(3000);
			peser();
			SDL_Delay(1000);
			stock();
			SDL_Delay(3000);

	SDL_DestroyWindow(getwindow());
	SDL_Quit();
	return 0;
}
