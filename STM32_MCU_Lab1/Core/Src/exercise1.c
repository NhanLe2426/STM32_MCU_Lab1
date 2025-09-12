/*
 * exercise1.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise1.h"

/* Defines */

/* Variables */
int RED_LED_status = 0; 	// 0 is ON; 1 is OFF
int RED_counter = 2;
int YELLOW_counter = 2;

/* Functions */
void toggleLED() {
	if (RED_LED_status == 0) {
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, SET);
		RED_counter--;
		if (RED_counter == 0) {
			RED_LED_status = 1;
			RED_counter = 2;
		}
	} else {
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, RESET);
		YELLOW_counter--;
		if (YELLOW_counter == 0) {
			RED_LED_status = 0;
			YELLOW_counter = 2;
		}
	}
}
