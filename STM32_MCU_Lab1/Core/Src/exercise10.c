/*
 * exercise7.c
 *
 *  Created on: Sep 18, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise10.h"

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

int hour = 0;
int min = 0;
int sec = 0;

/* Functions */
void setNumberOnClock(int num) {
	if (num < 0 || num > 11) return;

	HAL_GPIO_WritePin(LED_PORT[num], LED_Pin[num], RESET);
}

void clearNumberOnClock(int num) {
	if (num < 0 || num > 11) return;

	HAL_GPIO_WritePin(LED_PORT[num], LED_Pin[num], SET);
}

void clearAllClock() {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, SET);
}

void displayClock() {
	static int preHourPos = -1;
	static int preMinPos = -1;
	static int preSecPos = -1;

	int hourPos = hour;
	int minPos = min / 5;
	int secPos = sec / 5;

	if (preHourPos != -1 && preHourPos != hourPos)
		clearNumberOnClock(preHourPos);
	if (preMinPos != -1 && preMinPos != minPos)
		clearNumberOnClock(preMinPos);
	if (preSecPos != -1 && preSecPos != secPos)
		clearNumberOnClock(preSecPos);

	setNumberOnClock(hourPos);
	setNumberOnClock(minPos);
	setNumberOnClock(secPos);

	preHourPos = hourPos;
	preMinPos = minPos;
	preSecPos = secPos;

	sec++;
	if (second == 60) {
		sec = 0;
		min++;
		if (min == 60) {
			min = 0;
			hour = hour + 1;
			if (hour == 12) {
				hour = 0;
			}
		}
	}
}
