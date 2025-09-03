/*
 * File: main.c
 * Author: Adham Muhammed
 * Description:
 *   This file contains the main program for a smart home system.
 *   It monitors temperature, light intensity, and flame detection.
 *   Based on sensor readings, it controls a fan, LEDs, and a buzzer,
 *   displaying real-time data on an LCD screen.
 */

#include "dcmotor.h"
#include "led.h"
#include "flame_sensor.h"
#include "lm35_sensor.h"
#include "ldr_sensor.h"
#include "buzzer.h"
#include "lcd.h"
#include "adc.h"
#include <util/delay.h>

int main(void)
{
	/* Variables to hold motor status, speed, temperature, and light intensity */
	DcMotor_State motor_status = STOP;
	uint8 motor_speed = 0;
	uint8 temp = 0;
	uint16 light = 0;

	/* Initialize peripherals */
	/* Initialize the ADC */
	ADC_init();
	LEDS_init();
	FlameSensor_init();
	Buzzer_init();
	LCD_init();
	DcMotor_Init();

	while(1)
	{
		LCD_clearScreen();

		/* Check for fire detection */
		if (FlameSensor_getValue() == FIRE)
		{
			Buzzer_on();
			LCD_displayString("CRITICAL ALERT!");
			while (FlameSensor_getValue() == FIRE);  // Wait until fire is gone
			Buzzer_off();
		}
		else
		{
			/* Display fan status, temperature, and light intensity */
			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ");
			LCD_moveCursor(1,0);
			LCD_displayString("Temp=");
			LCD_moveCursor(1,8);
			LCD_displayString("LDR=");
			LCD_moveCursor(1,15);
			LCD_displayCharacter('%');

			while (FlameSensor_getValue() != FIRE)
			{
				/* Display fan state */
				LCD_moveCursor(0,10);
				if (motor_status == STOP)
				{
					LCD_displayString("OFF");
				}
				else
				{
					LCD_displayString("ON ");
				}

				/* Read sensor values */
				temp = LM35_getTemperature();
				light = LDR_getLightIntensity();

				/* Adjust fan speed based on temperature */
				if (temp < 25)
				{
					motor_status = STOP;
					motor_speed = 0;
				}
				else if (temp >= 25 && temp < 30)
				{
					motor_status = CLOCKWISE;
					motor_speed = 25;
				}
				else if (temp >= 30 && temp < 35)
				{
					motor_status = CLOCKWISE;
					motor_speed = 50;
				}
				else if (temp >= 35 && temp < 40)
				{
					motor_status = CLOCKWISE;
					motor_speed = 75;
				}
				else
				{
					motor_status = CLOCKWISE;
					motor_speed = 100;
				}

				/* Adjust LED brightness based on light intensity */
				if (light <= 15)
				{
					LED_on(LED_RED);
					LED_on(LED_GREEN);
					LED_on(LED_BLUE);
				}
				else if (light >= 16 && light <= 50)
				{
					LED_on(LED_RED);
					LED_on(LED_GREEN);
					LED_off(LED_BLUE);
				}
				else if (light >= 51 && light <= 70)
				{
					LED_on(LED_RED);
					LED_off(LED_GREEN);
					LED_off(LED_BLUE);
				}
				else
				{
					LED_off(LED_RED);
					LED_off(LED_GREEN);
					LED_off(LED_BLUE);
				}

				/* Rotate motor according to status and speed */
				DcMotor_Rotate(motor_status, motor_speed);

				/* Display temperature and light intensity */
				LCD_moveCursor(1,5);
				LCD_intgerToString((int)temp);
				if (temp < 100) LCD_displayCharacter(' ');
				LCD_moveCursor(1,12);
				LCD_intgerToString((int)light);
				if (light < 100) LCD_displayCharacter(' ');
			}
		}
	}
}
