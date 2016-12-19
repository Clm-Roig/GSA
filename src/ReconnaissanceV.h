#ifndef DEF_ReconnaissanceV
#define DEF_ReconnaissanceV

// EN-TETE ReconnaissanceV.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Couleur.c"
#include "BDD.c"
#include "LecteurBMP.c"

// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "data/images_aliments/";

// ---- FONCTIONS ---- //

/**
	@brief Teste si la couleur de fond est clairement discernable ou pas
	@param FILE* image, l'image que l'on souhaite analyser
	@return int, 1 (True) si une couleur de fond a été repérée, sinon 0 (False)
*/
int unifierFond(FILE* image);

/**
	@brief Renvoie la couleur dominante de l'image si elle a pu être identifié
	@param FILE* image, l'image que l'on souhaite analyser
	@return Couleur, la couleur dominante de l'image
*/
Couleur* couleurDominante(FILE* image);

/**
    @brief Renseigne sur la présence (ou non) d'au moins un aliment ayant une couleur proche du paramètre
	@param Couleur* coul, la couleur que l'on souhaite utiliser pour chercher des aliments
	@return int, 1 (True) s'il existe au moins un aliment proche de la couleur, 0 (False)
*/
int rechercheAliment(Couleur* coul);

/**
	@brief Renvoie un tableau des ids des aliments qui ont une couleur proche de celle passée en paramètre
	@param Couleur* coul, la couleur que l'on souhaite utiliser pour chercher des aliments
	@return int*, la tableau des aliments proches de la couleur passée en paramètre
*/
int* IdAlimentsDeCouleur(Couleur* coul);

#endif
