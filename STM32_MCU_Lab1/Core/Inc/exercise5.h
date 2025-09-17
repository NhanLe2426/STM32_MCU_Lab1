/*
 * exercise3.h
 *
 *  Created on: Sep 13, 2025
 *      Author: ASUS
 */

#ifndef INC_EXERCISE5_H_
#define INC_EXERCISE5_H_

/* Includes */
#include "main.h"
#include "led_7seg.h"

/* Variables */
extern int currentState;
extern int counter;

/* Functions */
// Control the North-South traffic light
extern void setLight_NS(int red, int yellow, int green);
// Control the East-West traffic light
extern void setLight_EW(int red, int yellow, int green);
// 4-ways traffic light
extern void trafficLight4Ways();

#endif /* INC_EXERCISE5_H_ */
