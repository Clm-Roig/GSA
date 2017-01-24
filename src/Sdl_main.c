#include "Sdl_main.h"

int main(int argc,char* args[]) {
/*
	int loop = 1;
	int page = 1;

	// Affichage de différentes fenetres
	init();

	while(loop==1){

		if(page==1) page = menu();
		else if(page==2) page = peser();
		else if(page==3) page = stock();
		else if(page==0) loop = 0;

	}

	cleanup();
*/

	Couleur* coul = initCouleurAvecParam(208,201,30);
	int i;
	getIdAlimentParCouleur(coul);

	return 0;
}
