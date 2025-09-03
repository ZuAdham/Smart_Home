/*
 * File: ldr_sensor.c
 * Author: Adham Muhammed
 * Description:
 *   This file contains the implementation of the LDR (Light Dependent Resistor) sensor module.
 *   It provides a function to read the light intensity using the ADC and convert it into a meaningful value.
 */

#include "ldr_sensor.h"
#include "adc.h"

/*
 * Function: LDR_getLightIntensity
 * --------------------------------
 * Reads the ADC value from the LDR sensor channel and calculates the light intensity.
 *
 * Parameters: None
 *
 * Returns:
 *   uint16 - The calculated light intensity value.
 */
uint16 LDR_getLightIntensity(void)
{
    uint16 adc_value = 0;
    uint16 light_value = 0;

    /* Read ADC channel where the LDR sensor is connected */
    adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    /* Calculate the light intensity from the ADC value */
    light_value = (uint16)(((uint32)adc_value * LDR_SENSOR_MAX_LIGHT_VALUE * ADC_REF_VOLT_VALUE) /
                           (ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT_VALUE));

    return light_value;
}
