// EN-TETE ReconnaissanceV.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Couleur.h"
#include "BDD.h"

#ifndef DEF_ReconnaissanceV
#define DEF_ReconnaissanceV


// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "data/images_aliments/";

// ---- FONCTIONS ---- //

// STRUCTURE D'UN FICHIER BITMAP : http://sitelec.org/cours/abati/bmp.htm
/**
	@brief Récupère l'en-tête d'un fichier .bmp
	@param FILE* image, l'image à charger
	@return un tableau de char contenant l'en-tête du fichier
*/
unsigned char* getEnTete(FILE* image);

/**
	@brief Renseigne sur la largeur de l'image
	@param FILE* image, l'image à charger
	@return bool, 1 si l'image a une largeur (en pxl) multiple de 4, sinon 0
*/
int formatLargeurBMP(FILE* image);

/**
	@brief Charge les données d'une image BITMAP (.bmp) dans un tableau de Couleurs
	@param FILE* image, l'image à charger
	@return Couleur*, tableau de Couleurs représentant l'image chargée
*/
Couleur* getDonnees(FILE* image);


int unifierFond(FILE* image);
//Renvoie True (1) si la caméra a clairement pu identifier le fond, sinon False (0)
//image E images_aliments

Couleur couleurDominante(FILE* image);
//Renvoie True si la couleur dominante de la photo a clairement pu être #identifiée, False sinon.
//couleurDominante(FILE * image1) => unifierFond(FILE * imageFond)

int rechercheAliment(Couleur);
//Renvoie True(1) si il y a au moins un aliment dans la base de donnée qui est proche de la couleur dominante, sinon False (0)
//rechercheAliment(Couleur) => Couleur==couleurDominante(FILE *)

int* IdAlimentsDeCouleur(Couleur);
//renvoie les ids des aliments qui ont une Couleur proche de celle rentrée en paramètre


#endif
