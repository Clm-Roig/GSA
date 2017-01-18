#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/ReconnaissanceV.c"
#include "src/Couleur.c"
#include "src/BDD.c"
#include "src/ImageBMP.c"

int main() {
	// Ouvrir la photo
		// => FILE* => initImageBMP() ImageBMP (img)

	// L'analyser (couleurDominanteHorsFond)
		// => Couleur* blanc = initCouleurAvecParam(255,255,255)
		// => coul = couleurDominanteHorsFond(img,blanc)

	// Inscrire cette couleur en BDD
		// => coul à parser en R-G-B (getRCoul()...)
		// => concaténer les 3 composantes (avec des tirets) grâce à sprintf(str,"%d",getRcoul())
		// => sauver en BDD ecrireDonneesAliment(.....)

	// Renommer la photo
		// => rename sur FILE* (ou à la main)
    FILE* fichier = fopen("data/pesees.txt","a");


    return 0;
}
