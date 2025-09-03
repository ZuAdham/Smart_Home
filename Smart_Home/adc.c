/*
 * File: adc.c
 * Author: Adham Muhammed
 * Description:
 *   This file contains the implementation of the ADC (Analog-to-Digital Converter) driver.
 *   It initializes the ADC module and provides a function to read analog values from a specific channel.
 */

#include "adc.h"
#include "common_macros.h"
#include "avr/io.h"

/*
 * Function: ADC_init
 * ------------------
 * Initializes the ADC module by setting the reference voltage and the prescaler.
 *
 * Parameters: None
 *
 * Returns: None
 */
void ADC_init(void)
{
	/* Set the reference voltage */
	ADMUX = (ADMUX & ADMUX_REF_SELECT_MASK) | (3 << ADMUX_REF_SELECT_BITS_POS);

	/* Enable ADC */
	SET_BIT(ADCSRA, ADEN);

	/* Set ADC prescaler */
	ADCSRA = (ADCSRA & ADCSRA_PRESCALER_SELECT_MASK) | (7 << ADCSRA_PRESCALER_SELECT_BITS_POS);
}

/*
 * Function: ADC_readChannel
 * -------------------------
 * Reads the ADC value from the specified channel.
 *
 * Parameters:
 *   ch_num - The ADC channel number to read from (0 to 31).
 *
 * Returns:
 *   uint16 - The digital value converted from the analog input.
 *            Returns 0 if the channel number is invalid.
 */
uint16 ADC_readChannel(uint8 ch_num)
{
	/* Validate channel number */
	if (ch_num > 0x1F)
	{
		return 0;
	}

	/* Select ADC channel */
	ADMUX = (ADMUX & ADMUX_CH_SELECT_MASK) | (ch_num << ADMUX_CH_SELECT_BITS_POS);

	/* Start conversion */
	SET_BIT(ADCSRA, ADSC);

	/* Wait for conversion to complete */
	while (BIT_IS_CLEAR(ADCSRA, ADIF));

	/* Clear ADC interrupt flag */
	SET_BIT(ADCSRA, ADIF);

	/* Return ADC result */
	return ADC;
}
