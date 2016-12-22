#include "ReconnaissanceV.h"
// ---- FONCTIONS ---- //

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

    int i = 0;
    for(i; i < (image->hauteur * image->largeur) ; i++) {
        varR = varR + (getRCoul(image->couleurs[i]) - moyenneR) * (getRCoul(image->couleurs[i]) - moyenneR);
        varG = varG + (getGCoul(image->couleurs[i]) - moyenneG) * (getGCoul(image->couleurs[i]) - moyenneG);
        varB = varB + (getBCoul(image->couleurs[i]) - moyenneB) * (getBCoul(image->couleurs[i]) - moyenneB);
    }

    varR = varR / (image->hauteur * image->largeur);
    varG = varG / (image->hauteur * image->largeur);
    varB = varB / (image->hauteur * image->largeur);

    float ecarR = sqrt(varR);
    float ecarG = sqrt(varG);
    float ecarB = sqrt(varB);

    // Condition sur la variance (à ajuster)
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

    int i = 0;
    for(i; i < (image->hauteur * image->largeur) ; i++) {
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


int rechercheAliment(Couleur* coul) {
    int res = 0;
    return res;
}


int* IdAlimentsDeCouleur(Couleur* coul) {

}


