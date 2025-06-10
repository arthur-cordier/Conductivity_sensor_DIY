/*
 * m24m01e.c
 *
 *  Created on: Mar 6, 2025
 *      Author: arthur
 */

#include "m24m01e.h"
#include <stdio.h>
#include <math.h> // Pour isnan

//========================================================================
//								EEPROM
//========================================================================
#define M24M01E_I2C_ADDRESS  0x50  						// Adresse I2C de l'M24M01E

#define M24M01E_PAGE_SIZE    256   						// Taille d'une page en octets
#define M24M01E_TIMEOUT      1000  						// Timeout pour les opérations I2C
#define M24M01E_MAX_ENTRIES  (131072 / sizeof(float)) 	// Nombre max de valeurs stockables

//========================================================================
//							FONCTION EEPROM
//========================================================================
/* INITIALISATION DE L'EEPROM
 *
 * Vérifie sur la mémoire est détéctée avant d'effectuer des actions dessus
 * Réinitialise entierement la mémoire au démarrage
 */
HAL_StatusTypeDef M24M01E_Init(I2C_HandleTypeDef *hi2c) {

	if (HAL_I2C_IsDeviceReady(hi2c, M24M01E_I2C_ADDRESS << 1, 3, M24M01E_TIMEOUT) != HAL_OK) {
	    printf("Erreur : EEPROM M24M01E non detectee !\n\r");
	    return HAL_ERROR;
	}

    return M24M01E_Clear(hi2c);
    printf("EEPROM M24M01E réinitialisee :  prete pour stockage de donnees\n\r");
}

/* EFFACEMENT DE LA MEMOIRE
 *
 * Cette fonction efface entièrement l'EEPROM M24M01E en remplissant toute la mémoire avec 0xFF, ce qui est la valeur par défaut d'une EEPROM vierge.
 */
HAL_StatusTypeDef M24M01E_Clear(I2C_HandleTypeDef *hi2c) {
    uint8_t reset_data[M24M01E_PAGE_SIZE];        	//tableau de taille M24M01E_PAGE_SIZE
    memset(reset_data, 0xFF, M24M01E_PAGE_SIZE);	//remplit tout le tableau avec 0xFF

    //boucle pour parcourir toute la memoire page par page et l'effacer en utilisant HAL_I2C_Mem_Write() pour écrire via I2C
    for (uint16_t addr = 0; addr < 131072; addr += M24M01E_PAGE_SIZE) {
        if (HAL_I2C_Mem_Write(hi2c, M24M01E_I2C_ADDRESS << 1, addr, I2C_MEMADD_SIZE_16BIT, reset_data, M24M01E_PAGE_SIZE, M24M01E_TIMEOUT) != HAL_OK) {
            return HAL_ERROR;
        }
        HAL_Delay(5); //La mémoire a un temps d'écriture de 4 ms donc on lui laisse le temps d'ecrire
    }
    return HAL_OK;
}

/* ECRITURE EN CONTINU AVEC SUPPRESSIOND ES ANCIENNES VALEURS SI LA MEMOIRE EST PLEINE
 *
 * Cette fonction écrit une valeur de salinité dans l'EEPROM via I2C
 * Elle utilise un mode d'écriture circulaire : si la mémoire est pleine, les anciennes valeurs sont écrasées
 */
HAL_StatusTypeDef M24M01E_WriteSalinity(I2C_HandleTypeDef *hi2c, float salinity) {
    static uint16_t lastIndex = 0;                                         	//index du dernier emplacement utilisé dans l'EEPROM (initialisé a 0)
    uint16_t address = (lastIndex % M24M01E_MAX_ENTRIES) * sizeof(float);   //adresse mémoire où écrire la valeur de salinité
    uint8_t buffer[4];														//un float fait 4 octets, mais l'I2C n'écrit que des tableaux d'octets
    memcpy(buffer, &salinity, sizeof(float));								//on copie donc les 4 octets du float salinity dans buffer[]

    //écrit buffer[] (la valeur de salinité) à l'adresse memoire calculée en utilisant HAL_I2C_Mem_Write() pour envoyer les données via I2C.
    if (HAL_I2C_Mem_Write(hi2c, M24M01E_I2C_ADDRESS << 1, address, I2C_MEMADD_SIZE_16BIT, buffer, sizeof(float), M24M01E_TIMEOUT) != HAL_OK) {
        return HAL_ERROR;
    }
    HAL_Delay(5);

    lastIndex = (lastIndex + 1) % M24M01E_MAX_ENTRIES; // Rotation circulaire des données (la division euclidienne des deux valeurs retourne le reste)
    return HAL_OK;
}

/* LECTURE D'UNE VALEUR DE SALINITE
 *
 * Cette fonction permet de lire une valeur de salinité stockée dans la mémoire M24M01E via I2C.
 */
HAL_StatusTypeDef M24M01E_ReadSalinity(I2C_HandleTypeDef *hi2c, uint16_t index, float *salinity) {
    uint16_t address = index * sizeof(float);	//convertit l’index en adresse mémoire où est stockée la valeur
    uint8_t buffer[4];							//déclare un tableau de 4 octets pour stocker la valeur de salinité lue

    //Lit la valeur stockée à l'adresse calculée (address) depuis la memoire en utilisant HAL_I2C_Mem_Read() pour récupérer la donnée en I2C.
    if (HAL_I2C_Mem_Read(hi2c, M24M01E_I2C_ADDRESS << 1, address, I2C_MEMADD_SIZE_16BIT, buffer, sizeof(float), M24M01E_TIMEOUT) != HAL_OK) {
        return HAL_ERROR;
    }

    memcpy(salinity, buffer, sizeof(float)); //copie les 4 octets du buffer vers salinity
    return HAL_OK;
}

/* AFFICHER TOUTES LES VALEURS DE SALINITE STOCKEES
 *
 * Cette fonction permet de lire toutes les valeurs de salinité stockée dans la mémoire M24M01E.
 */
void M24M01E_PrintAll(I2C_HandleTypeDef *hi2c) {
    float salinity; //déclare une variable salinity qui va contenir chaque valeur lue depuis la memoire

    //Parcourt tous les index possibles de la mémoire avec M24M01E_MAX_ENTRIES qui est le nombre total de valeurs stockables (128ko/4)
    //Si la lecture échoue ou si la valeur lue est NaN (valeur invalide), on arrete la boucle (break)
    for (uint16_t i = 0; i < M24M01E_MAX_ENTRIES; i++) {
        if (M24M01E_ReadSalinity(hi2c, i, &salinity) != HAL_OK || isnan(salinity)) {
            break;
        }

        //Affiche la valeur de salinité avec son index
        printf("Salinité [%d] : %.2f PSU\n\r", i, salinity);
    }
}
