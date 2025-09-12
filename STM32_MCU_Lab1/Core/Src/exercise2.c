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

int RED_counter = 5;
int GREEN_counter = 3;
int YELLOW_counter = 2;

/* Functions */
void trafficLight() {
	if (currentState = RED_STATE) {
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, RESET); 		// RED is ON
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, SET);
		RED_counter--;
		if (RED_counter == 0) {
			RED_counter = 5;
			currentState = GREEN_STATE;
		}
	} else
	if (currentState == GREEN_STATE) {
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, RESET);	// GREEN is ON
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, SET);
		GREEN_counter--;
		if (GREEN_counter == 0) {
			GREEN_counter = 3;
			currentState = YELLOW_STATE;
		}
	} else
	if (currentState == YELLOW_STATE) {
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, RESET);	// YELLOW is ON
		YELLOW_counter--;
		if (YELLOW_counter == 0) {
			YELLOW_counter = 2;
			currentState = RED_STATE;
		}
	}
}
