/* Header des fonctions propres à la pesée d'aliments */ 
#include <stdio.h>
#include <stdlib.h>

/**
    @brief Retourne la valeur de la tare posée sur la balance après stabilisation
*/

float tare(); 

/**
    @brief Retourne la force mesurée par le capteur de force 
*/

float getForce(); 

/**
    @brief Retourne le poids calculé à partir de la valeur retournée par le capteur de force 
*/

float getPoids(); 
