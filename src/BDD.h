// EN-TETE BDD.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ---- CONSTANTES ---- //
const char* CHEMIN_PESEES = "data/pesees.txt";
const char* CHEMIN_ALIMENTS = "data/aliments.txt";
#define TAILLE_MAX_LIGNE 300

// ---- FONCTIONS ---- //

// ---- Lecture ---- //
/**
    @brief renvoie le nombre de lignes que contient un fichier
    @param FILE* fichier le fichier à analyser
    @return int le nombre de lignes du fichier
*/
int nbLignesFichier(FILE* fichier);

/**
    @brief renvoie la ligne du fichier pointé
    @param FILE* fichier le fichier que l'on souhaite lire
    @param int n le numéro de la ligne que l'on souhaite lire
    @return char* la ligne issue du fichier
*/
char* lireLigne(FILE* fichier, int n);

/**
    @brief renvoie l'id maximum contenu dans le fichier aliments.txt ou pesees.txt
    @param char* type le nom du fichier dont on souhaite connaître l'idMax (aliments ou pesees)
    @return int l'id maximum utilisé dans le fichier analysé
*/
int getIdMax(char* type);

/**
    @brief renvoie le tuple sans l'id du fichier spécifié
    @param FILE* fichier : le fichier dont on veut extraire une ligne
    @param int id : l'id du tuple que l'on souhaite obtenir
    @return char* le tuple complet sans l'id spécifié extrait du fichier
*/
char* lireLigneParId(FILE* fichier, int id);

// ALIMENTS
/**
    @brief renvoie le tuple sans l'id du fichier spécifié
    @param FILE* fichier : le fichier dont on veut extraire une ligne
    @param int id : l'id du tuple que l'on souhaite obtenir
    @return char* le tuple complet sans l'id spécifié extrait du fichier
*/
char* getNomAlimentParId(int id);

/**
    @brief renvoie la couleur de l'aliment ciblé par l'id
    @param int id : l'id de l'aliment dont on souhaite la couleur
    @return char* la couleur de l'aliment (format r-g-b)
*/
char* getCouleurAlimentParId(int id);

// PESEES


// ----- Ecriture ---- //

int ecrireDonneeAliment(char* nom, char* couleur);
int ecrireDonneePesee(int quantite,char* description,char* date,int id_aliment);
