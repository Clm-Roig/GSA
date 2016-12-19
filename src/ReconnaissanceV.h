#ifndef DEF_ReconnaissanceV
#define DEF_ReconnaissanceV

// EN-TETE ReconnaissanceV.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Couleur.c"
#include "BDD.c"

// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "data/images_aliments/";

// ---- FONCTIONS ---- //

/**
	@brief Renvoie True (1) si la caméra a clairement pu identifier le fond, sinon False (0)
	@param FILE* image, l'image prise comme fond
	@return int, (1) si l'opération a été clairement réalisée, (0) sinon
*/
int unifierFond(FILE* image);

/**
	@brief Renvoie la couleur dominante de la photosi elle a pu être identifiée, sinon renvoie une erreur
	@param FILE* image, l'image prise en photo
	@return Couleur, la couleur dominante de la photo
*/
Couleur couleurDominante(FILE* image);

/**
	@brief Renvoie True(1) si il y a au moins un aliment dans la base de donnée qui est proche de la couleur dominante, sinon False (0)
	@param Couleur, la couleur pass&ée en paramètre correspond souvent à la couleur dominante d'une photo
	@return int, un booléen (1) si l existe au moins un aliment de la coumleur, (0) sinon
*/
int rechercheAliment(Couleur);

/**
	@brief Renvoie un tableau d'ids, les ids correspondant à celles des aliments qui ont une couleur proche de celle rentrée en paramètre.
	@param Couleur, la couleur pass&ée en paramètre correspond souvent à la couleur dominante d'une photo
	@return int*, un tableau de int,
*/
int* IdAlimentsDeCouleur(Couleur);

#endif
