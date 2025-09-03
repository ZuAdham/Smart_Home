
/******************************************************************************
 *
 * Module: Flame_Sensor
 *
 * File Name: flame_sensor.c
 *
 * Description: Source file for the AVR Flame_Sensor driver
 *
 * Author: Adham Muhammed
 *
 *******************************************************************************/

#include "flame_sensor.h"
#include "gpio.h"

/*
 * Function: FlameSensor_init
 * --------------------------
 * Initializes the flame sensor by setting the sensor pin as input.
 *
 * Parameters: None
 *
 * Returns: None
 */
void FlameSensor_init(void)
{
    /* Set the flame sensor pin as input */
    GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

/*
 * Function: FlameSensor_getValue
 * ------------------------------
 * Reads the current status of the flame sensor.
 *
 * Parameters: None
 *
 * Returns:
 *   uint8 - FIRE (LOGIC_HIGH) if fire is detected, NO_FIRE (LOGIC_LOW) otherwise.
 */
uint8 FlameSensor_getValue(void)
{
    return GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);
}
