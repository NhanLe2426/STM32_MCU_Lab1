/*
 * exercise9.c
 *
 *  Created on: Sep 18, 2025
 *      Author: ASUS
 */

#include "exercise9.h"

/* Variables */
GPIO_TypeDef* LED_PORT[12] = {
		LED_0_GPIO_Port, LED_1_GPIO_Port, LED_2_GPIO_Port,
		LED_3_GPIO_Port, LED_4_GPIO_Port, LED_5_GPIO_Port,
		LED_6_GPIO_Port, LED_7_GPIO_Port, LED_8_GPIO_Port,
		LED_9_GPIO_Port, LED_10_GPIO_Port, LED_11_GPIO_Port
};

uint16_t LED_Pin[12] = {
		LED_0_Pin, LED_1_Pin, LED_2_Pin, LED_3_Pin,
		LED_4_Pin, LED_5_Pin, LED_6_Pin, LED_7_Pin,
		LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin
};

void clearNumberOnClock(int num) {
	if (num < 0 || num > 11) return;

	HAL_GPIO_WritePin(LED_PORT[num], LED_Pin[num], SET);
}
