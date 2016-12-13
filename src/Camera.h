// EN-TETE Camera.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef DEF_Camera
#define DEF_Camera


// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "data/images_aliments/";

// ---- FONCTIONS ---- //

char* demarrerCamera();

/**
	@brief Démarre la caméra
	@param pas de paramètres
	@return bool, 1 si la caméra s'est correctement allumée, 0 sinon
*/

char* prendrePhoto();

/**
	@brief Prend une photo
	@param pas de paramètres
	@return bool, 1 si la prise de photo s'est bien passée, 0 sinon
*/

char* enregistrerPhoto();

/**
	@brief Enregistrer la photo
	@param FILE* image, 
	@return bool, 1 si la photo , 0 sinon
*/
