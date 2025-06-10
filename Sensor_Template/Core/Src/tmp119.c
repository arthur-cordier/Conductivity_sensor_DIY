/*
 * tmp119.c
 *
 *  Created on: Mar 6, 2025
 *      Author: arthur
 */

#include "tmp119.h"

//========================================================================
//							PRESSURE SENSOR
//========================================================================
#define TMP119_I2C_ADDRESS 0x48  // Adresse par défaut si ADD0 est à GND

//========================================================================
//			REGISTER ADDRESS MAP
//========================================================================
#define TMP119_TEMP_REG 0x00     // Registre de température

//========================================================================
//							GET TEMPERATURE
//========================================================================
HAL_StatusTypeDef ReadTemperature(I2C_HandleTypeDef *hi2c, float *temperature) {
	//déclaration des variables
    uint8_t temp_reg = TMP119_TEMP_REG; //Contient l'adresse du registre de température
    uint8_t temp_data[2]; 				//On pourrait stocker uniquement 256 valeurs différentes (0 à 255) et impossible d'avoir des valeurs négatives. Avec deux bits, On peut stocker 65536 valeurs. On garde une précision fine de 0.0078125°C par bit.
    int16_t raw_temp; 					//Variable pour convertir les octets en valeur signée 16 bits

    /*SELECTION DU REGISTRE DE TEMPERATURE
     *
     *Avant de lire la température, on doit dire au capteur qu’on veut accéder au registre 0x00
     *On envoie cette information via I2C avec HAL_I2C_Master_Transmit()
     *Si la transmission échoue, on retourne HAL_ERROR
     */
    if (HAL_I2C_Master_Transmit(hi2c, TMP119_I2C_ADDRESS << 1, &temp_reg, 1, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }

    /*LECTURE DES 2 OCTETS CONTENANT LA TEMPERATURE
     *
     *Après avoir sélectionné le registre, on récupère 2 octets de température depuis le capteur
     *Si la réception échoue, on retourne HAL_ERROR
     */
    if (HAL_I2C_Master_Receive(hi2c, TMP119_I2C_ADDRESS << 1, temp_data, 2, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }

    raw_temp = (int16_t)((temp_data[0] << 8) | temp_data[1]); //CONVERTIR LES OCTETS EN VALEUR DECIMAL BRUTE
    *temperature = raw_temp * 0.0078125f; //CONVERTIR EN °C

    return HAL_OK;
}

