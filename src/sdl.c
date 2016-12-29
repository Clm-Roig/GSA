#include <SDL2/SDL.h>
#include <stdio.h>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;

void menu(SDL_Surface* screenSurface, SDL_Window* window){
	SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,44, 62, 80));
			

			SDL_Rect buttEnreg;SDL_Rect buttInv;
			buttEnreg.x=40; buttEnreg.y=40; buttEnreg.w=350; buttEnreg.h=400;
			buttInv.x=400; buttInv.y=40; buttInv.w=350; buttInv.h=400;
			SDL_FillRect(screenSurface,&buttEnreg,SDL_MapRGB(screenSurface->format,192, 57, 43));
			SDL_FillRect(screenSurface,&buttInv,SDL_MapRGB(screenSurface->format,211, 84, 0));
			SDL_UpdateWindowSurface(window);
}
void peser(SDL_Surface* screenSurface, SDL_Window* window){
	SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,44, 62, 80));
	//RAJOUTER VEUILLER PATIENTER
	//RAJOUTTER POID
	SDL_UpdateWindowSurface(window);
}
void stock(SDL_Surface* screenSurface, SDL_Window* window){
	SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,44, 62, 80));

	SDL_Rect objet1;SDL_Rect objet2; SDL_Rect objet3; SDL_Rect objet4; SDL_Rect objet5;
	objet1.x=40; objet1.y=40; objet1.w=60; objet1.h=60;
	objet2.x=40; objet2.y=125; objet2.w=60; objet2.h=60;
	objet3.x=40; objet3.y=210; objet3.w=60; objet3.h=60;
	objet4.x=40; objet4.y=295; objet4.w=60; objet4.h=60;
	objet5.x=40; objet5.y=380; objet5.w=60; objet5.h=60;

	SDL_FillRect(screenSurface,&objet1,SDL_MapRGB(screenSurface->format,192, 57, 43));
	SDL_FillRect(screenSurface,&objet2,SDL_MapRGB(screenSurface->format,192, 57, 43));
	SDL_FillRect(screenSurface,&objet3,SDL_MapRGB(screenSurface->format,192, 57, 43));
	SDL_FillRect(screenSurface,&objet4,SDL_MapRGB(screenSurface->format,192, 57, 43));
	SDL_FillRect(screenSurface,&objet5,SDL_MapRGB(screenSurface->format,192, 57, 43));

	SDL_UpdateWindowSurface(window);
}

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
			
			//MENU
			menu(screenSurface, window);
			SDL_Delay(3000);
			peser(screenSurface, window);
			SDL_Delay(1000);
			stock(screenSurface, window);
			SDL_Delay(3000);

						
			}
		
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
