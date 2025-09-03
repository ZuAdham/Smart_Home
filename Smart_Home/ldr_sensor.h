/******************************************************************************
 *
 * Module: Light Sensor (LDR)
 *
 * File Name: ldr_sensor.h
 *
 * Description: Header file for the Light Dependent Resistor (LDR) sensor driver.
 *              This module provides functions to read and convert ADC values
 *              into light intensity percentages.
 *
 * Author: Adham Muhammed
 *
 *******************************************************************************/

#ifndef LDR_SENSOR_H_
#define LDR_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* ADC Channel to which the LDR sensor is connected */
#define LDR_SENSOR_CHANNEL_ID         0

/* Maximum voltage output from the LDR sensor */
#define LDR_SENSOR_MAX_VOLT_VALUE     2.56

/* Maximum light intensity percentage */
#define LDR_SENSOR_MAX_LIGHT_VALUE    100

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Reads the ADC value from the LDR sensor and converts it into a light intensity percentage.
 */
uint16 LDR_getLightIntensity(void);

#endif /* LDR_SENSOR_H_ */
