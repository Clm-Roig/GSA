// EN-TETE ReconnaissanceV.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Couleur.c"
#include "BDD.c"

#ifndef DEF_LecteurBMP
#define DEF_LecteurBMP

//TODO : ajouter une structure stockant les diverses informations de l'image

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
	@param FILE* image, l'image à analyser
	@return bool, 1 si l'image a une largeur (en pxl) multiple de 4, sinon 0
*/
int getLargeurBMP(FILE* image);

/**
	@brief Retourne la taille de l'image
	@param FILE* image, l'image à analyser
	@return long, la taille de l'image
*/
long getTailleFichier(FILE* image);

/**
	@brief Charge les données d'une image BITMAP (.bmp) dans un tableau de Couleurs
	@param FILE* image, l'image à charger
	@return Couleur*, tableau de Couleurs représentant l'image chargée
*/
Couleur* getDonnees(FILE* image);


#endif
