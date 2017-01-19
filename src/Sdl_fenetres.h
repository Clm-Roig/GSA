#include <SDL2/SDL.h>
#include <stdio.h>
#include "BDD.h"
#include "Stock.h"
#include "Sdl_init.h"

/**
	@brief Modifie le rendu pour le menu de choix d'action
	@return 1 si on doit aller au menu, 2 si à la peser, 3 si au stock, 0 pour quitter
*/
void menu();

/**
	@brief Modifie le rendu pour la page de pesee
	@return 1 si on doit aller au menu, 2 si à la peser, 3 si au stock, 0 pour quitter
*/
void peser();

/**
	@brief Modifie le rendu pour la page des stocks
	@return 1 si on doit aller au menu, 2 si à la peser, 3 si au stock, 0 pour quitter
*/
void stock();
