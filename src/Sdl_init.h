#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define SCREEN_WIDTH 800;
#define SCREEN_HEIGHT 480;

/**
	@brief Recupère le renderer actuellement utilisé
	@return Pointeur vers le SDL_Renderer utilisé
*/
SDL_Renderer *getrenderer();
/**
	@brief Recupère la fenetre actuellement utilisé
	@return Pointeur vers le SDL_Window utilisé
*/
SDL_Window *getwindow();

/**
	@brief Initilialise une fenetre pour le programme
*/
void init();

/**
	@brief Detruit la fenetre, le rendu et ferme SDL
*/
void cleanup();
