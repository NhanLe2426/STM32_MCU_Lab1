/*
 * exercise7.c
 *
 *  Created on: Sep 18, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise7.h"

/* Functions */
void clearAllClock() {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, SET);
}
