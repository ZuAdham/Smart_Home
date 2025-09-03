/*
 * File: lcd.c
 * Author: Adham Muhammed
 * Description:
 *   This file contains the implementation of the LCD driver.
 *   It provides functions for initializing and interacting with the LCD.
 */

#include "lcd.h"
#include "gpio.h"
#include <util/delay.h>
#include <stdlib.h>

/*
 * Function: LCD_init
 * ------------------
 * Initializes the LCD by configuring control and data pins.
 * Sets the display mode and clears the screen.
 *
 * Parameters: None
 *
 * Returns: None
 */
void LCD_init(void)
{
    /* Configure RS, Enable, and Data Port pins as output */
    GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, PIN_OUTPUT);
    GPIO_setupPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);

    /* Wait for LCD to power up */
    _delay_ms(20);

    /* Initialize LCD in 8-bit mode */
    LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
    LCD_sendCommand(LCD_CURSOR_OFF);
    LCD_sendCommand(LCD_CLEAR_COMMAND);
}

/*
 * Function: LCD_sendCommand
 * -------------------------
 * Sends a command to the LCD.
 *
 * Parameters:
 *   command - The command to be sent to the LCD.
 *
 * Returns: None
 */
void LCD_sendCommand(uint8 command)
{
    /* Set RS to LOW for command mode */
    GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW);
    _delay_ms(1);

    /* Enable LCD */
    GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_HIGH);
    _delay_ms(1);

    /* Send command */
    GPIO_writePort(LCD_DATA_PORT_ID, command);
    _delay_ms(1);

    /* Disable LCD */
    GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_LOW);
    _delay_ms(1);
}

/*
 * Function: LCD_displayCharacter
 * ------------------------------
 * Displays a single character on the LCD.
 *
 * Parameters:
 *   character - The character to be displayed.
 *
 * Returns: None
 */
void LCD_displayCharacter(char character)
{
    /* Set RS to HIGH for data mode */
    GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH);
    _delay_ms(1);

    /* Enable LCD */
    GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_HIGH);
    _delay_ms(1);

    /* Send character */
    GPIO_writePort(LCD_DATA_PORT_ID, character);
    _delay_ms(1);

    /* Disable LCD */
    GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_LOW);
    _delay_ms(1);
}

/*
 * Function: LCD_displayString
 * ---------------------------
 * Displays a string on the LCD.
 *
 * Parameters:
 *   string - Pointer to the string to be displayed.
 *
 * Returns: None
 */
void LCD_displayString(char *string)
{
    uint8 i;
    for (i = 0; string[i] != '\0'; i++)
    {
        LCD_displayCharacter(string[i]);
    }
}

/*
 * Function: LCD_moveCursor
 * ------------------------
 * Moves the cursor to a specific row and column on the LCD.
 *
 * Parameters:
 *   row - The row number (0-3).
 *   col - The column number (0-15).
 *
 * Returns: None
 */
void LCD_moveCursor(uint8 row, uint8 col)
{
    uint8 lcd_memory_address;

    /* Calculate memory address based on row and column */
    switch (row)
    {
    case 0:
        lcd_memory_address = col;
        break;
    case 1:
        lcd_memory_address = col + LCD_SECOND_ROW_ADDRESS;
        break;
    case 2:
        lcd_memory_address = col + LCD_THIRD_ROW_ADDRESS;
        break;
    case 3:
        lcd_memory_address = col + LCD_FOURTH_ROW_ADDRESS;
        break;
    }

    /* Set cursor location */
    LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Function: LCD_displayStringRowColumn
 * ------------------------------------
 * Displays a string at a specific row and column on the LCD.
 *
 * Parameters:
 *   row - The row number (0-3).
 *   col - The column number (0-15).
 *   string - Pointer to the string to be displayed.
 *
 * Returns: None
 */
void LCD_displayStringRowColumn(uint8 row, uint8 col, char *string)
{
    LCD_moveCursor(row, col);
    LCD_displayString(string);
}

/*
 * Function: LCD_intgerToString
 * ----------------------------
 * Converts an integer to a string and displays it on the LCD.
 *
 * Parameters:
 *   data - The integer value to be displayed.
 *
 * Returns: None
 */
void LCD_intgerToString(int data)
{
    char buff[LCD_MAX_CHAR_PER_ROW];
    itoa(data, buff, 10);
    LCD_displayString(buff);
}

/*
 * Function: LCD_clearScreen
 * -------------------------
 * Clears the LCD screen.
 *
 * Parameters: None
 *
 * Returns: None
 */
void LCD_clearScreen(void)
{
    LCD_sendCommand(LCD_CLEAR_COMMAND);
}
