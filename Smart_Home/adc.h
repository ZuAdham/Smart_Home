/******************************************************************************
 *
 * Module: ADC (Analog-to-Digital Converter)
 *
 * File Name: adc.h
 *
 * Description: Header file for the ADC driver, providing initialization
 *              and channel reading functionalities.
 *
 * Author: Adham Muhammed
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADMUX_REF_SELECT_MASK         0x3F
#define ADMUX_REF_SELECT_BITS_POS     6

#define ADCSRA_PRESCALER_SELECT_MASK  0xF8
#define ADCSRA_PRESCALER_SELECT_BITS_POS 0

#define ADMUX_CH_SELECT_MASK          0xE0
#define ADMUX_CH_SELECT_BITS_POS      0

#define ADC_REF_VOLT_VALUE            2.56
#define ADC_MAXIMUM_VALUE             1023

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initializes the ADC module by setting up the reference voltage
 * and prescaler configuration.
 */
void ADC_init(void);

/*
 * Description :
 * Reads the ADC value from the specified channel.
 *
 * Parameters:
 *  - ch_num: ADC channel number (0 to 31).
 *
 * Returns:
 *  - uint16: The digital ADC value.
 */
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
