#include "LecteurBMP.h"

// Init + destroy
ImageBMP* initImageBMP(FILE* fichier) {
    ImageBMP* image = malloc(sizeof(ImageBMP));
    image->couleurs = getDonnees(fichier);
    image->taille_image = getTailleImage(fichier);
    image->taille_fichier = getTailleFichier(fichier);
    return image;
}

void destroyImageBMP(ImageBMP* image) {
    free(image);
    image = NULL;
}

// Fonctions
unsigned char* getEnTete(FILE* image) {
    unsigned char* enTete = malloc(54*sizeof(unsigned char));
    unsigned char octet;

    // L'en-tête d'un fichier Bitmap fait 54 octets
    int i;
    for (i=0 ; i < 54 ; i++) {
        fread(&octet,sizeof(octet),1,image);
        enTete[i] = octet;
    }
    fseek(image,0,0);
    return enTete;
}

int getLargeurBMP(FILE* image) {
    unsigned char* enTete = getEnTete(image);
    // Pas la peine d'aller chercher plus loin que l'octet 19, la largeur ne dépassera jamais 4096 pixels (16^3)
    int largeur = enTete[18] + 16*16*enTete[19];
    return largeur;
}

long getTailleImage(FILE* image) {
    // Cette information n'est pas toujours présente dans les fichiers BMP
    // On la calcule "manuellement" en sachant que l'en-tête fait toujours 54 octetc.
    return getTailleFichier(image) - 54;
}

long getTailleFichier(FILE* image) {
    unsigned char* enTete = getEnTete(image);
    long a = enTete[2];
    long b = 16*16*enTete[3];
    long c = 16*16*16*16*enTete[4];
    long d = 16*16*16*16*16*16*enTete[5];
    long taille_fichier = a + b + c + d;
    return taille_fichier;
}

ImageBMP* getDonnees(FILE* image, ImageBMP* imageBMP) {
    long taille_image = getTailleImage(image);
    int largeur_image = getLargeurBMP(image);

    imageBMP->couleurs = malloc(taille_image*sizeof(Couleur *));

    unsigned char octet;

    // Offset contiendra le nombre octet ajouté à chaque ligne pour compléter
    // celle-ci de manière à ce que ce soit un multiple de 4
    int offset = largeur_image%4;

    // On se positionne au début des couleurs (octet 54)
    fseek(image,54,SEEK_SET);

    // p compte le nombre de pixels lus
    long p=0;
    // i compte le nombre composante de couleurs lues
    long i=0;

    // Attention : pour chaque pixel, les composantes sont stockées à l'envers en Bitmap (BGR)
    while(i < taille_image) {
        Couleur* coul = initCouleur();

        fread(&octet,sizeof(octet),1,image);
        setBCoul((int)octet,coul);

        fread(&octet,sizeof(octet),1,image);
        setGCoul((int)octet,coul);

        fread(&octet,sizeof(octet),1,image);
        setRCoul((int)octet,coul);

        imageBMP->couleurs[p] = coul;

        printf("R: %d",getRCoul(imageBMP->couleurs[p]));
        printf(" G: %d",getGCoul(imageBMP->couleurs[p]));
        printf(" B: %d\n",getBCoul(imageBMP->couleurs[p]));

        // On a lu 1 pixel et 3 couleurs.
        p++;
        i += 3;

        // On "saute" le(s) dernier(s) pixel(s) de la ligne s'il y a un offset.
        if(p%largeur_image == 0) {
            if(offset==1) {
                fseek(image,1,SEEK_CUR);
                i++;
            }
            if(offset==2) {
                fseek(image,2,SEEK_CUR);
                i += 2;
            }
            if(offset==3) {
                fseek(image,3,SEEK_CUR);
                i += 3;
            }
        }
    }
    // image parcourue entièrement

    return imageBMP;
}
