/*
 * exercise1.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise1.h"

/* Defines */
#define RED_STATE		0
#define YELLOW_STATE	1

/* Variables */
int currentState = RED_STATE;
int counter = 2;

/* Functions */
void toggleLED() {
	switch (currentState) {
	case RED_STATE:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, SET);
		counter--;
		if (counter == 0) {
			currentState = YELLOW_STATE;
			counter = 2;
		}
		break;

	case YELLOW_STATE:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, RESET);
		counter--;
		if (counter == 0) {
			currentState = RED_STATE;
			counter = 2;
		}
		break;
	}
}
