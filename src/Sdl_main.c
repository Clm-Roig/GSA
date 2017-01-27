#include "Sdl_main.h"

int main(int argc,char* args[]) {

	int loop = 1;
	int page = 1;

	// Affichage de différentes fenetres
	init();

	while(loop==1){

		if(page==1) page = menu();
		else if(page==2) page = peser();
		else if(page==3) page = stock();
		else if(page==0) loop = 0;
		else if(page==-1) {
			printf("Erreur interface");
			loop = 0;
		}

	}

	cleanup();

/*
	if (1){
		reinitPesees();
		ecrireDonneePesee(1,"Une pesee à Clément",20);
		ecrireDonneePesee(200,"Une pesee à Clément",14);
		ecrireDonneePesee(150,"Une pesee à Clément",3);
		ecrireDonneePesee(100,"Fruits frais",20);
		ecrireDonneePesee(500,"Description random",1);
		ecrireDonneePesee(15,"Une pesee à Clément",2);
	}
	else {
		supprimerDonneePesee(4);
	}
*/
/*

	Couleur* coul = initCouleurAvecParam(180,146,19);
	int* liste = getIdAlimentParCouleur(coul);
	int i;
	for(i=0; i<5 ;i++){
		printf("\n%d",liste[i]);
	}
*/

	return 0;
}
