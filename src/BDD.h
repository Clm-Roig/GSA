/* En-têtes BDD.h 
 
	Les tuples de la BDD sont de la forme : 
		ID;ATTRIBUT1;ATTRIBUT2...
		3;passionnant;cool
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/* ----- CHEMINS D'ACCES DES DONNEES  */
#define CHEMIN_PESEES "/data/pesees/"
#define CHEMIN_ALIMENTS "/data/aliments/"
#define CHEMIN_IMAGES_ALIMENTS "/data/images_aliment/"


/**
	@brief: ouvre le fichier demandé. Retourne True si ok, sinon False
	@param char * cheminFichier chemin du fichier de données
	@return File * le fichier ouvert
 */
FILE* ouvrirFichier(char * cheminFichier);

/**
	@brief: ouvre le fichier demandé dans le répertoire des aliments
	@param char * nomFichier nom du fichier de données
	@return File * le fichier ouvert
 */
FILE* ouvrirFichierAliment(char * nomFichier);

/**
	@brief: ouvre le fichier demandé dans le répertoire des pesées
	@param char * nomFichier nom du fichier de données
	@return File * le fichier ouvert
 */
FILE* ouvrirFichierPesee(char * nomFichier);

/**
	@brief: ouvre le fichier demandé dans le répertoire des images d'aliments
	@param char * nomFichier nom du fichier de données
	@return File * le fichier ouvert
 */
FILE* ouvrirFichierImagesAliment(char * nomFichier);

/**
	@brief: ferme le fichier demandé.
	@param char * nomFichier nom du fichier de données à fermer
	@return int 1 si tout c'est bien passé, sinon 0
 */
int fermerFichier(char * nomFichier); 

/**
	@brief: écrit la donnée dans le fichier spécifié. Retourne True si ok, sinon False
	@param char * donnee la donnée à écrire en BDD
	@param char * nomFichier nom du fichier de données dans lequel on veut écrire 
	@return int 1 si tout c'est bien passé, sinon 0
 */
int ecrireDonnee(char * nomFichier, char * donnee);


/**
	@brief: lit la donnée associée à l'id assé en paramètre dans le fichier spécifié 
	@param int * id l'id de la donnée à lire
	@param char * nomFichier nom du fichier de données dans lequel on veut écrire 
	@return char la donnée associée à l'id 
 */
char lireDonnee(char * nomFichier, char * donnee);


/**
	@brief: renvoie un jeu de données issu de la BDD 
	@param char * donnee une chaine de caractère issue de la BDD
	@return char ** le tableau contenant la donnée découpée (retrait des ;)
 */
char ** parserDonnee(char * donnee);