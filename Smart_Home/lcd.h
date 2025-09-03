/******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver, providing function prototypes
 *              and macro definitions for LCD control.
 *
 * Author: Adham Muhammed
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LCD Control Pins */
#define LCD_RS_PORT_ID       PORTD_ID
#define LCD_RS_PIN_ID        PIN0_ID

#define LCD_ENABLE_PORT_ID   PORTD_ID
#define LCD_ENABLE_PIN_ID    PIN1_ID

/* LCD Data Port */
#define LCD_DATA_PORT_ID     PORTC_ID

/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

/* LCD Row Addresses */
#define LCD_FIRST_ROW_ADDRESS   0x00
#define LCD_SECOND_ROW_ADDRESS  0x40
#define LCD_THIRD_ROW_ADDRESS   0x10
#define LCD_FOURTH_ROW_ADDRESS  0x50

#define LCD_MAX_CHAR_PER_ROW    16  /* Maximum number of characters per row */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initializes the LCD in 4-bit or 8-bit mode as configured.
 */
void LCD_init(void);

/*
 * Description :
 * Sends a command to the LCD.
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * Displays a single character on the LCD.
 */
void LCD_displayCharacter(char character);

/*
 * Description :
 * Displays a string on the LCD.
 */
void LCD_displayString(char *string);

/*
 * Description :
 * Moves the cursor to a specific row and column on the LCD.
 */
void LCD_moveCursor(uint8 row, uint8 col);

/*
 * Description :
 * Displays a string at a specific position on the LCD.
 */
void LCD_displayStringRowColumn(uint8 row, uint8 col, char *string);

/*
 * Description :
 * Converts an integer to a string and displays it on the LCD.
 */
void LCD_intgerToString(int data);

/*
 * Description :
 * Clears the LCD screen.
 */
void LCD_clearScreen(void);

#endif /* LCD_H_ */
