#include "Sdl_init.h"

SDL_Window *screen;
SDL_Renderer *renderer;



SDL_Renderer *getrenderer(){
    return renderer;
}
SDL_Window *getwindow(){
    return screen;
}

void init(){
	int screenwidth; int screenheight;
	screenwidth = SCREEN_WIDTH;
	screenheight = SCREEN_HEIGHT;

    screen = SDL_CreateWindow("Coal - Connected ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screenwidth, screenheight,SDL_WINDOW_OPENGL|SDL_WINDOW_BORDERLESS);

    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode écran à : %s\n", SDL_GetError());
        exit(1);
    }

    //Initialisation du chargement des images png avec SDL_Image 2
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image n'a pu être initialisée! SDL_image Error: %s\n", IMG_GetError() );
        exit(1);
    }

}

void cleanup(){
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;

    SDL_Quit();
}