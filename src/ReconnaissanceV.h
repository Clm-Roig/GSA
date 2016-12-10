// EN-TETE ReconnaissanceV.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Couleur.c"
#include "BDD.c"
// ---- CONSTANTES ---- //

// ---- FONCTIONS ---- //

Couleur* chargerImage(FILE* image);
# Renvoie un tableau de Couleur représentant l'image chargée

bool unifierFond(FILE* image);
#Renvoie True si la caméra a clairement pu identifier le fond, False #sinon
#image E images_aliments

Couleur couleurDominante(FILE* image);
#Renvoie True si la couleur dominante de la photo a clairement pu être #identifiée, False sinon.
#couleurDominante(FILE * image1) => unifierFond(FILE * imageFond)

bool rechercheAliment(Couleur);
#Renvoie True si il y a au moins un aliment dans la base de donnée qui est proche de la couleur dominante, False sinon
#rechercheAliment(Couleur) => Couleur==couleurDominante(FILE *)

int* IdAlimentsDeCouleur(Couleur);
# renvoie les ids des aliments qui ont une Couleur proche de celle rentrée en paramètre

