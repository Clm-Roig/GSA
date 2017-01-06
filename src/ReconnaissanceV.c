#include "ReconnaissanceV.h"
// ---- FONCTIONS ---- //

// Fonction racine carré rapide
float fast_sqrtf(float number) {
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = * ( long * ) &y;         // evil floating point bit level hacking
	i = 0x5f3759df - ( i >> 1 ); // what the fuck?
	y = * ( float * ) &i;
	y = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
    y = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration

	return 1/y;
}
// -----------------------------------

int estUni(ImageBMP* image) {
    int res = 0;

    // On récupère la couleur moyenne de l'image
    Couleur* coulDominante = couleurDominante(image);
    int moyenneR = getRCoul(coulDominante);
    int moyenneG = getGCoul(coulDominante);
    int moyenneB = getBCoul(coulDominante);

    // Calcul des variances / écarts-type
    float varR = 0;
    float varG = 0;
    float varB = 0;

    int i;
    for(i=0; i < (image->hauteur * image->largeur) ; i++) {
        varR = varR + (getRCoul(image->couleurs[i]) - moyenneR) * (getRCoul(image->couleurs[i]) - moyenneR);
        varG = varG + (getGCoul(image->couleurs[i]) - moyenneG) * (getGCoul(image->couleurs[i]) - moyenneG);
        varB = varB + (getBCoul(image->couleurs[i]) - moyenneB) * (getBCoul(image->couleurs[i]) - moyenneB);
    }

    varR = varR / (image->hauteur * image->largeur);
    varG = varG / (image->hauteur * image->largeur);
    varB = varB / (image->hauteur * image->largeur);

    float ecarR = fast_sqrtf(varR);
    float ecarG = fast_sqrtf(varG);
    float ecarB = fast_sqrtf(varB);

    // Condition sur l'écart-type (à ajuster)
    if (ecarR + ecarG + ecarB < PRECISION_COULEUR) {
        res = 1;
    }

    return res;
}

Couleur* couleurDominante(ImageBMP* image) {
    // Calcul des moyennes pour chaque composante
    float moyenneR = 0;
    float moyenneG = 0;
    float moyenneB = 0;

    int i;
    for(i=0; i < (image->hauteur * image->largeur) ; i++) {
        moyenneR += getRCoul(image->couleurs[i]);
        moyenneG += getGCoul(image->couleurs[i]);
        moyenneB += getBCoul(image->couleurs[i]);
    }

    moyenneR = moyenneR / (image->hauteur * image->largeur);
    moyenneG = moyenneG / (image->hauteur * image->largeur);
    moyenneB = moyenneB / (image->hauteur * image->largeur);

    Couleur* coulDominante = initCouleur();
    setRCoul((int)moyenneR,coulDominante);
    setGCoul((int)moyenneG,coulDominante);
    setBCoul((int)moyenneB,coulDominante);

    return coulDominante;
}

Couleur* couleurDominanteHorsFond(ImageBMP* image, Couleur* couleurFond) {
    // Initialisation moyenneRGB de l'aliment
    float moyenneRAliment = 0;
    float moyenneGAliment = 0;
    float moyenneBAliment = 0;

    int valeurRPixel;
    int valeurGPixel;
    int valeurBPixel;
    int valeurCouleurPixel;

    // initialisation compteurPixelsValides
    int cptPixelsHorsFond = 0;

    // Pour chaque pixel de l'image
    int i;
    for(i=0; i < (image->hauteur * image->largeur) ; i++) {
    //      SI NON(couleur Pixel ~ couleurFond +/- precision)
        valeurRPixel += getRCoul(image->couleurs[i]);
        valeurGPixel += getGCoul(image->couleurs[i]);
        valeurBPixel += getBCoul(image->couleurs[i]);
        valeurCouleurPixel = valeurRPixel + valeurGPixel + valeurBPixel;

        // TODO comparer par composantes
        if !((valeurCouleurPixel > couleurFond - PRECISION_COULEUR_HORS_FOND) && (valeurCouleurPixel < couleurFond + PRECISION_COULEUR_HORS_FOND)) {
    //      ALORS moyenneRGB += couleurPixel
    //      compteurPixelsValides ++
            moyenneRGBAliment += valeurCouleurPixel;
            moyenneRAliment += valeurRPixel;
            moyenneGAliment += valeurGPixel;
            moyenneBAliment += valeurBPixel;
            cptPixelsHorsFond ++;
        }
    }

    // Calcul des moyennes pour chaque composante
    moyenneRAliment = moyenneRAliment / cptPixelsHorsFond;
    moyenneGAliment = moyenneGAliment / cptPixelsHorsFond;
    moyenneBAliment = moyenneBAliment / cptPixelsHorsFond;

    Couleur* coulDominanteHorsFond = initCouleur();
    setRCoul((int)moyenneRAliment,coulDominanteHorsFond);
    setGCoul((int)moyenneGAliment,coulDominanteHorsFond);
    setBCoul((int)moyenneBAliment,coulDominanteHorsFond);

    return coulDominanteHorsFond;
}

int rechercheAliment(Couleur* coul) {
    int res = 0;
    char* listeAlim = getIdAlimentParCouleur(coul,PRECISION_COULEUR);
    if(listeAlim != NULL){
        res = 1;
    }
    return res;
}
