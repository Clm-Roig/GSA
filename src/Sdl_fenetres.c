#include "Sdl_fenetres.h"

void menu() {
	SDL_Surface* screenSurface;
	SDL_Surface* texteAjout;
	SDL_Surface* texteInv;

	// Fond bleu
	screenSurface=SDL_GetWindowSurface(getwindow());
	SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,44, 62, 80));

	// Boutons menu
	SDL_Rect buttEnreg; SDL_Rect buttInv;
	buttEnreg.x=40; buttEnreg.y=40; buttEnreg.w=350; buttEnreg.h=400;
	buttInv.x=400; buttInv.y=40; buttInv.w=350; buttInv.h=400;

	SDL_FillRect(screenSurface,&buttEnreg,SDL_MapRGB(screenSurface->format,192, 57, 43));
	SDL_FillRect(screenSurface,&buttInv,SDL_MapRGB(screenSurface->format,211, 84, 0));

	// Texte boutons
	SDL_Color couleurBlanc = {255, 255, 255};
	texteAjout = TTF_RenderText_Blended(getpolice(), "Ajout d'un aliment", couleurBlanc);
	texteInv = TTF_RenderText_Blended(getpolice(), "Mon stock", couleurBlanc);

	// Insertion du texte dans les boutons
	// TODO : les boutons doivent être des SDL_Surface et non des SDL_Rect pour pouvoir
	// y inscrire du texte dedans en exécutant SDL_BlitSurface()
	if(!SDL_BlitSurface(texteAjout,NULL,screenSurface,NULL)) {
		printf("Erreur Blit Surface  : %s\n", SDL_GetError());
	}

	SDL_UpdateWindowSurface(getwindow());
}


void peser() {
	SDL_Surface* screenSurface;
	screenSurface=SDL_GetWindowSurface(getwindow());
	SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,44, 62, 80));
	//RAJOUTER VEUILLER PATIENTER
	//RAJOUTTER POID
	SDL_UpdateWindowSurface(getwindow());
}


void stock() {
	SDL_Surface* screenSurface;
	screenSurface=SDL_GetWindowSurface(getwindow());
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

	SDL_UpdateWindowSurface(getwindow());
}
