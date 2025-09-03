/******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.h
 *
 * Description: Header file for the Flame Sensor driver, providing initialization
 *              and fire detection functions.
 *
 * Author: Adham Muhammed
 *
 *******************************************************************************/

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define FLAME_SENSOR_PORT_ID   PORTD_ID
#define FLAME_SENSOR_PIN_ID    PIN2_ID

#define FIRE                  LOGIC_HIGH  /* Fire detected */
#define NO_FIRE               LOGIC_LOW   /* No fire detected */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initializes the Flame Sensor by setting up the corresponding pin as input.
 */
void FlameSensor_init(void);

/*
 * Description :
 * Reads the flame sensor value to detect fire presence.
 *
 * Returns:
 *  - FIRE if fire is detected.
 *  - NO_FIRE if no fire is detected.
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
