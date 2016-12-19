#ifndef DEF_Camera
#define DEF_Camera

// EN-TETE Camera.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "data/images_aliments/";

// ---- FONCTIONS ---- //


/**
	@brief Démarre la caméra
	@return bool, 1 si la caméra s'est correctement allumée, 0 sinon
*/

int demarrerCamera();


/**
	@brief Prend une photo
	@return bool, 1 si la prise de photo s'est bien passée, 0 sinon
*/

int prendrePhoto();

/**
	@brief Enregistrer la photo dans CHEMIN_IMAGES_ALIMENTS
	@return bool, 1 si la photo a bien été enregistrée , 0 sinon
*/

int enregistrerPhoto();

#endif
