#include "Sdl_fenetres.h"

int menu() {
	SDL_Surface* screenSurface;
	SDL_Surface* texteAjout;
	SDL_Surface* texteInv;
	SDL_Rect pos;

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

	int larg = texteAjout->w;
	int haut = texteAjout->h;
	pos.x=buttEnreg.x + ((buttEnreg.w-larg)/2); pos.y=buttEnreg.y + ((buttEnreg.h-haut)/2);

	SDL_BlitSurface(texteAjout,NULL,screenSurface,&pos);

	larg = texteInv->w;
	haut = texteInv->h;
	pos.x =buttInv.x + ((buttInv.w-larg)/2); pos.y=buttInv.y + ((buttInv.h-haut)/2);
	SDL_BlitSurface(texteInv,NULL,screenSurface,&pos);

	SDL_UpdateWindowSurface(getwindow());

	SDL_Event event;
	int loop = 1;
	while(loop == 1) {
		int x = -1; int y = -1;

	    SDL_WaitEvent(&event);
	    switch(event.type)
	    {
	        case SDL_MOUSEBUTTONUP:
	        	x = event.button.x;
	            y = event.button.y;
	            break;
	        case SDL_FINGERDOWN:
	        	x = event.tfinger.x;
	            y = event.tfinger.y;
	            break;
	        case SDL_KEYDOWN:
	            switch(event.key.keysym.sym)
	            {
	            	case SDLK_ESCAPE:
	                    loop= 0;
	                    return 0;
	                    break;
	                }
	                break;
	    }

	    if((x>=buttEnreg.x)&&(x<=(buttEnreg.x+buttEnreg.w))&&(y>=buttEnreg.y)&&(y<=(buttEnreg.y+buttEnreg.h))){
	 		return 2;
	    }
	    else if((x>=buttInv.x)&&(x<=(buttInv.x+buttInv.w))&&(y>=buttInv.y)&&(y<=(buttInv.y+buttInv.h))){
	 		return 3;
	    }
	    else{

	    }
	}
}

int peserPhoto(SDL_Surface* screenSurface){
	SDL_Surface* texteRetour;
	SDL_Rect pos;
	SDL_Surface* texteGo;

	SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,44, 62, 80));

	// Bouton Retour
	SDL_Rect buttRetour; SDL_Color couleurBlanc = {255, 255, 255};
	buttRetour.x=0; buttRetour.y=0; buttRetour.w=45; buttRetour.h=30;
	SDL_FillRect(screenSurface,&buttRetour,SDL_MapRGB(screenSurface->format,211, 84, 0));
	texteRetour = TTF_RenderText_Blended(getpolice(), "<", couleurBlanc);
	int larg = texteRetour->w;
	int haut = texteRetour->h;
	pos.x=buttRetour.x + ((buttRetour.w-larg)/2); pos.y=buttRetour.y + ((buttRetour.h-haut)/2);
	SDL_BlitSurface(texteRetour,NULL,screenSurface,&pos);

	// Boutons menu
	SDL_Rect buttGo;
	buttGo.x=225; buttGo.y=40; buttGo.w=350; buttGo.h=400;

	SDL_FillRect(screenSurface,&buttGo,SDL_MapRGB(screenSurface->format,192, 57, 43));

	// Texte boutons
	texteGo = TTF_RenderText_Blended(getpolice(), "Prendre Photo", couleurBlanc);

	larg = texteGo->w;
	haut = texteGo->h;
	pos.x = buttGo.x + ((buttGo.w-larg)/2); pos.y=buttGo.y + ((buttGo.h-haut)/2);

	SDL_BlitSurface(texteGo,NULL,screenSurface,&pos);

	SDL_UpdateWindowSurface(getwindow());
	SDL_Event event;
	int loop = 1;
	while(loop==1){
		int x = -1; int y = -1;
	    SDL_WaitEvent(&event);
	    switch(event.type)
		{
	        case SDL_MOUSEBUTTONUP:
	        	x = event.button.x;
	            y = event.button.y;
	            break;
	        case SDL_FINGERDOWN:
	        	x = event.tfinger.x;
	            y = event.tfinger.y;
	            break;
	        case SDL_KEYDOWN:

	            switch(event.key.keysym.sym) {
	            	case SDLK_ESCAPE:
	                    loop= 0;
	                    return 0;
	                    break;
	            }
	                break;
	    }

		// Clic Boutons
	    if((x>=buttRetour.x)&&(x<=(buttRetour.x+buttRetour.w))&&(y>=buttRetour.y)&&(y<=(buttRetour.y+buttRetour.h))){
	 		return 0;
	    }
		else if((x>=buttGo.x)&&(x<=(buttGo.x+buttGo.w))&&(y>=buttGo.y)&&(y<=(buttGo.y+buttGo.h))){
	 		return 2;
	    }
	    else {

	    }
	}
}

int peserLoading(SDL_Surface* screenSurface) {
	SDL_Rect pos;
	SDL_Surface* texteTitre;
	SDL_Color couleurBlanc = {255, 255, 255};

	SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,44, 62, 80));

	// Afficher patientez
	texteTitre = TTF_RenderText_Blended(getpolice(), "Veuillez patienter", couleurBlanc);
	pos.x = (800-(texteTitre->w))/2;
	pos.y = 240;
	SDL_BlitSurface(texteTitre,NULL,screenSurface,&pos);

	SDL_UpdateWindowSurface(getwindow());

	// On lance la premiere photo (fond) et on la contrôle
	FILE* fic;
	ImageBMP* img;
	int photoPrise;

	do {
		char* nomPhoto = "fond";
		char* chemin = NULL;
		chemin = malloc(100*sizeof(char));
		strcpy(chemin,CHEMIN_IMAGES_ALIMENTS);
	    strcat(chemin,nomPhoto);
		strcat(chemin,".bmp");

		photoPrise = prendrePhoto(nomPhoto);

		fic = fopen(chemin, "rb");
		if (!fic) {
			printf("Erreur ouverture fichier");
		}
		img = initImageBMP(fic);
		fclose(fic);
		remove(chemin);

		if(estUni(img) != 1) {
			// Afficher "Veuillez choisir un fond uni svp."
		}
	} while(estUni(img) != 1 || photoPrise != 1);

	return 3; //On passe au menu suivant
}

int peserBase(SDL_Surface* screenSurface){
	SDL_Surface* texteRetour;
	SDL_Rect pos;
	SDL_Surface* texteGo;

	SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,44, 62, 80));
	//Boutton Retour
	SDL_Rect buttRetour; SDL_Color couleurBlanc = {255, 255, 255};
	buttRetour.x=0; buttRetour.y=0; buttRetour.w=45; buttRetour.h=30;
	SDL_FillRect(screenSurface,&buttRetour,SDL_MapRGB(screenSurface->format,211, 84, 0));
	texteRetour = TTF_RenderText_Blended(getpolice(), "<", couleurBlanc);
	int larg= texteRetour->w;
	int haut= texteRetour->h;
	pos.x=buttRetour.x + ((buttRetour.w-larg)/2); pos.y=buttRetour.y + ((buttRetour.h-haut)/2);
	SDL_BlitSurface(texteRetour,NULL,screenSurface,&pos);

	// Boutons menu
	SDL_Rect buttGo;
	buttGo.x=225; buttGo.y=40; buttGo.w=350; buttGo.h=400;

	SDL_FillRect(screenSurface,&buttGo,SDL_MapRGB(screenSurface->format,192, 57, 43));

	// Texte boutons
	texteGo = TTF_RenderText_Blended(getpolice(), "Initialiser", couleurBlanc);

	larg= texteGo->w;
	haut= texteGo->h;
	pos.x=buttGo.x + ((buttGo.w-larg)/2); pos.y=buttGo.y + ((buttGo.h-haut)/2);

	SDL_BlitSurface(texteGo,NULL,screenSurface,&pos);

	SDL_UpdateWindowSurface(getwindow());
	SDL_Event event;
	int loop = 1;
	while(loop==1){
		int x = -1; int y = -1;
	    SDL_WaitEvent(&event);
	    switch(event.type)
	    {
	        case SDL_MOUSEBUTTONUP:
	        	x = event.button.x;
	            y = event.button.y;
	            break;
	        case SDL_FINGERDOWN:
	        	x = event.tfinger.x;
	            y = event.tfinger.y;
	            break;
	        case SDL_KEYDOWN:
	            switch(event.key.keysym.sym)
	            {
	            	case SDLK_ESCAPE:
	                    loop= 0;
	                    return 0;
	                    break;
	                }
	                break;
	    }
	    if((x>=buttRetour.x)&&(x<=(buttRetour.x+buttRetour.w))&&(y>=buttRetour.y)&&(y<=(buttRetour.y+buttRetour.h))){
	 		return 0;
	    }
		else if((x>=buttGo.x)&&(x<=(buttGo.x+buttGo.w))&&(y>=buttGo.y)&&(y<=(buttGo.y+buttGo.h))){
	 		return 2; //On passe au menu suivant
	    }
	    else{

	    }
	}
}

int peser() {
	SDL_Surface* screenSurface;
	screenSurface=SDL_GetWindowSurface(getwindow());

	int loop = 1;
	int page = 1;

	while(loop==1) {
		if(page==1) page = peserBase(screenSurface);
		else if(page==2) page = peserLoading(screenSurface);
		else if(page==3) page = peserPhoto(screenSurface);
		else if(page==0) loop = 0;
	}

	return 1;
}

int stock() {
	SDL_Surface* screenSurface;
	SDL_Surface* texteTitre;
	SDL_Surface* texteMenu;
	SDL_Rect pos;

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

	// Texte
	SDL_Color couleurBlanc = {255, 255, 255};

	texteTitre = TTF_RenderText_Blended(getpolice(), "Mon stock", couleurBlanc);
	pos.x = (800-(texteTitre->w))/2;
	pos.y = 10;
	SDL_BlitSurface(texteTitre,NULL,screenSurface,&pos);

	// Bouton Menu
	SDL_Rect buttMenu;
	buttMenu.x=0; buttMenu.y=0; buttMenu.w=45; buttMenu.h=30;
	SDL_FillRect(screenSurface,&buttMenu,SDL_MapRGB(screenSurface->format,211, 84, 0));
	texteMenu = TTF_RenderText_Blended(getpolice(), "<", couleurBlanc);
	int larg = texteMenu->w;
	int haut = texteMenu->h;
	pos.x = buttMenu.x + ((buttMenu.w-larg)/2);
	pos.y = buttMenu.y + ((buttMenu.h-haut)/2);
	SDL_BlitSurface(texteMenu,NULL,screenSurface,&pos);

	SDL_UpdateWindowSurface(getwindow());

	SDL_Event event;
	int loop = 1;
	while(loop==1){
		int x = -1; int y = -1;
	    SDL_WaitEvent(&event);
	    switch(event.type)
	    {
	        case SDL_MOUSEBUTTONUP:
	        	x = event.button.x;
	            y = event.button.y;
	            break;
	        case SDL_FINGERDOWN:
	        	x = event.tfinger.x;
	            y = event.tfinger.y;
	            break;
	        case SDL_KEYDOWN:
	            switch(event.key.keysym.sym)
	            {
	            	case SDLK_ESCAPE:
	                    loop= 0;
	                    return 0;
	                    break;
	                }
	                break;
	    }
	    if((x>=buttMenu.x)&&(x<=(buttMenu.x+buttMenu.w))&&(y>=buttMenu.y)&&(y<=(buttMenu.y+buttMenu.h))){
	 		return 1;
	    }
	    else {

	    }
	}
}
