/*
 * exercise3.c
 *
 *  Created on: Sep 13, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise3.h"

/* Define */
#define INIT_STATE	0
#define NS_GREEN	1		// North-South GREEN
#define NS_YELLOW	2		// North-South YELLOW
#define EW_GREEN 	3		// East-West GREEN
#define EW_YELLOW 	4		// East-West YELLOW

/* Variables */
int currentState = INIT_STATE;
int counter;				// GREEN LED is 3s

/* Functions */
// Control the North-South traffic light
void setLight_NS(int red, int yellow, int green) {
	HAL_GPIO_WritePin(N_RED_LED_GPIO_Port, N_RED_LED_Pin, red);
	HAL_GPIO_WritePin(N_YEL_LED_GPIO_Port, N_YEL_LED_Pin, yellow);
	HAL_GPIO_WritePin(N_GRN_LED_GPIO_Port, N_GRN_LED_Pin, green);

	HAL_GPIO_WritePin(S_RED_LED_GPIO_Port, S_RED_LED_Pin, red);
	HAL_GPIO_WritePin(S_YEL_LED_GPIO_Port, S_YEL_LED_Pin, yellow);
	HAL_GPIO_WritePin(S_GRN_LED_GPIO_Port, S_GRN_LED_Pin, green);
}

// Control the East-West traffic light
void setLight_EW(int red, int yellow, int green) {
	HAL_GPIO_WritePin(E_RED_LED_GPIO_Port, E_RED_LED_Pin, red);
	HAL_GPIO_WritePin(E_YEL_LED_GPIO_Port, E_YEL_LED_Pin, yellow);
	HAL_GPIO_WritePin(E_GRN_LED_GPIO_Port, E_GRN_LED_Pin, green);

	HAL_GPIO_WritePin(W_RED_LED_GPIO_Port, W_RED_LED_Pin, red);
	HAL_GPIO_WritePin(W_YEL_LED_GPIO_Port, W_YEL_LED_Pin, yellow);
	HAL_GPIO_WritePin(W_GRN_LED_GPIO_Port, W_GRN_LED_Pin, green);
}

// 4-ways traffic light
void trafficLight4Ways() {
	switch (currentState) {
	case INIT_STATE:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, SET);
		currentState = NS_GREEN;
		counter = 3;
		break;

	case NS_GREEN:
		setLight_NS(SET, SET, RESET);		// North-South is GREEN
		setLight_EW(RESET, SET, SET);		// East-West is RED
		counter--;
		if (counter == 0) {
			currentState = NS_YELLOW;
			counter = 2;					// YELLOW LED is 2s
		}
		break;

	case NS_YELLOW:
		setLight_NS(SET, RESET, SET);		// North-South is YELLOW
		setLight_EW(RESET, SET, SET);		// East-West is RED
		counter--;
		if (counter == 0) {
			currentState = EW_GREEN;
			counter = 3;					// GREEN LED is 3s
		}
		break;

	case EW_GREEN:
		setLight_NS(RESET, SET, SET);		// North-South is RED
		setLight_EW(SET, SET, RESET);		// East-West is GREEN
		counter--;
		if (counter == 0) {
			currentState = EW_YELLOW;
			counter = 2;					// YELLOW LED is 2s
		}
		break;

	case EW_YELLOW:
		setLight_NS(RESET, SET, SET);		// North-South is RED
		setLight_EW(SET, RESET, SET);		// East-West is YELLOW
		counter--;
		if (counter == 0) {
			currentState = NS_GREEN;
			counter = 3;					// GREEN LED is 3s
		}
		break;
	}
}
