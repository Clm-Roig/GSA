#ifndef DEF_BDD
#define DEF_BDD

// EN-TETE BDD.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "Couleur.c"

// ---- CONSTANTES ---- //
const char* CHEMIN_ALIMENTS = "data/aliments.txt";
const char* CHEMIN_PESEES = "data/pesees.txt";
const char* CHEMIN_ALIMENTS_TEMP = "data/aliments.txt.tmp";
const char* CHEMIN_PESEES_TEMP = "data/pesees.txt.tmp";

const char* ENTETE_ALIMENTS = "ID_ALIMENT;NOM_ALIMENT;COULEUR_ALIMENT\n";
const char* ENTETE_PESEES = "ID_PESEE;QUANTITE_PESEE;DESCRIPTION_PESEE;DATE_PESEE;ID_ALIMENT_PESEE\n";
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
Couleur* getCouleurAliment(int id);

/**
    @brief renvoie la liste des id des aliments (id1;id2;id3...) qui ont une couleur proche de la couleur spécifiée
    @param char* : couleur la couleur dont on cherche des aliments
    @param int : precision sur la couleur (pour la couleur 50-50-50, une precision de 10 cherche toutes les couleurs entre 40-40-40 et 60-60-60)
    @return char* la liste des ids des aliments une couleur proche de celle spécifiée
*/
char* getIdAlimentParCouleur(Couleur* coul,int precision);

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

// ----- Modification ---- //
/**
    @brief Permet de modifier la quantité d'un aliment pesé
    @param int id : le numero id de l'aliment dont on veut changer la quantité
    @param int nouvQte : la nouvelle quantité de l'aliment
    @return int 1 si modification ok, sinon 0
*/
int setQuantitePesee(int id, int nouvQte);

/**
    @brief Permet de modifier la date d'enregistrement d'un aliment pesé
    @param int id : le numero id de l'aliment dont on veut changer la date d'enregistrement
    @return int 1 si modification ok, sinon 0
*/
int setDatePesee(int id, char* nouvDate);

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

// ----- Suppression ---- //
/**
    @brief supprime le tuple Aliment spécifié par l'id
    @param int id: l'id du tuple aliment à supprimer
    @return int 1 si suppression ok, sinon 0
*/
int supprimerDonneeAliment(int id);

/**
    @brief supprime le tuple Pesée spécifié par l'id
    @param int id: l'id du tuple pesée à supprimer
    @return int 1 si suppression ok, sinon 0
*/
int supprimerDonneePesee(int id);


#endif
