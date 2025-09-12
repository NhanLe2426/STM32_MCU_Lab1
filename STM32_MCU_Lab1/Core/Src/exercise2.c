/*
 * exercise2.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise2.h"

/* Define */
#define RED_STATE 		0
#define GREEN_STATE 	1
#define YELLOW_STATE 	2

/* Variables */
int currentState = RED_STATE;
int counter = 5;

/* Functions */
void trafficLight() {
	switch (currentState) {
	case RED_STATE:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, RESET); 		// RED is ON
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, SET);
		counter--;
		if (counter == 0) {
			currentState = GREEN_STATE;
			counter = 3;
		}
		break;

	case GREEN_STATE:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, RESET);	// GREEN is ON
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, SET);
		counter--;
		if (counter == 0) {
			currentState = YELLOW_STATE;
			counter = 2;
		}
		break;

	case YELLOW_STATE:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, RESET);	// YELLOW is ON
		counter--;
		if (counter == 0) {
			currentState = RED_STATE;
			counter = 5;
		}
		break;
	}
}
