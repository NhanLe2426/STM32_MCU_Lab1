/*
 * exercise6.c
 *
 *  Created on: Sep 17, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise6.h"

/* Functions */
void displayLED(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, RESET);
		break;

	case 1:
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
		break;

	case 2:
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET);
		break;

	case 3:
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, RESET);
		break;

	case 4:
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, RESET);
		break;

	case 5:
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, RESET);
		break;

	case 6:
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, RESET);
		break;

	case 7:
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, RESET);
		break;

	case 8:
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, RESET);
		break;

	case 9:
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, RESET);
		break;

	case 10:
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, RESET);
		break;

	case 11:
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
		break;

	default:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, SET);
	}
}
