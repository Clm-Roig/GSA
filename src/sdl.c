#include <SDL2/SDL.h>
#include <stdio.h>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;

int main(int argc,char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO)<0) {
		printf("Could not initialize SDL. SDL_Error: %s\n",SDL_GetError());
	} else {
		window = SDL_CreateWindow("Coal - Connected ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_OPENGL|SDL_WINDOW_BORDERLESS);
		if (window==NULL) {
			printf("Cannot create window. SDL_Error: %s\n",SDL_GetError());
		} else {
			
			screenSurface=SDL_GetWindowSurface(window);
			// On Choisi la couleur du fond de l'app
			SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,100,100,100));
			

			SDL_Rect buttEnreg;SDL_Rect buttInv;
			buttEnreg.x=40; buttEnreg.y=40; buttEnreg.w=350; buttEnreg.h=400;
			buttInv.x=400; buttInv.y=40; buttInv.w=350; buttInv.h=360;
			SDL_FillRect(screenSurface,&buttEnreg,SDL_MapRGB(screenSurface->format,150,0,0));
			SDL_FillRect(screenSurface,&buttInv,SDL_MapRGB(screenSurface->format,150,90,0));
			SDL_UpdateWindowSurface(window);
						
			SDL_Delay(3000);}
		
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
