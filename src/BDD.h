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
char* getNomAliment(int id);

/**
    @brief renvoie la couleur de l'aliment ciblé par l'id
    @param int id : l'id de l'aliment
    @return char* la couleur de l'aliment (format r-g-b)
*/
char* getCouleurAliment(int id);

// PESEES

/**
    @brief renvoie la quantite de la pesee ciblée par l'id
    @param int id : l'id de la pesee
    @return char* la quantite pesee
*/
char* getQuantitePesee(int id);

/**
    @brief renvoie la description de la pesee ciblée par l'id
    @param int id : l'id de la pesee
    @return char* la description de la pesee
*/
char* getDescriptionPesee(int id);

/**
    @brief renvoie la date de la pesee ciblée par l'id
    @param int id : l'id de la pesee
    @return char* la date de la pesee
*/
char* getDatePesee(int id);

/**
    @brief renvoie l'id de l'aliment de la pesee ciblée par l'id
    @param int id : l'id de la pesee
    @return char* l'id de l'aliment pesee
*/
char* getIdAlimentPesee(int id);

// ----- Ecriture ---- //
/**
    @brief écrit un tuple aliment (ID / NOM / COULEUR)
    @param char* nom : le nom de l'aliment
    @param char* couleur : la couleur de l'aliment (format : R-G-B)
    @return int 1 si écriture ok, sinon 0
*/
int ecrireDonneeAliment(char* nom, char* couleur);

/**
    @brief écrit un tuple pesee (ID / QUANTITE / DESCRIPTION / DATE / ID_ALIMENT)
    @param int quantite : la quantité d'aliment pesée
    @param char* description : la description de la pesée
    @param char* date : la date de la pesée (TODO : format à préciser (heures ? minutes ?)
    @param int id_aliment : l'id de l'aliment pesé
    @return int 1 si écriture ok, sinon 0
*/
int ecrireDonneePesee(int quantite,char* description,char* date,int id_aliment);
