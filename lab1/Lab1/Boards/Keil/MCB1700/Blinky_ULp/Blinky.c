/*
 * COE 718 - Lab 1
 * Student: Ali Israr
 * Student ID: 501242427
 * Section: 07
 *
 * Description:
 * This program reads the MCB1700 joystick and displays the
 * last detected direction on the LCD while also indicating
 * the direction using the LEDs.
 */

#include <stdio.h>          // Standard input/output functions
#include <stdint.h>         // Provides fixed-width integer types
#include "Blinky.h"         // Main program definitions
#include "LPC17xx.h"        // LPC1768 microcontroller definitions
#include "GLCD.h"           // LCD functions
#include "LED.h"            // LED functions
#include "KBD.h"            // Joystick functions

#define __FI 1              // Selects the LCD font
#define __USE_LCD 1         // Enables LCD functionality

int main(void)
{
    uint32_t joystick;      // Stores the current joystick value

    LED_Init();             // Initializes the LEDs as outputs
    KBD_Init();             // Initializes the joystick as GPIO inputs

		#if __USE_LCD

			GLCD_Init();            // Initializes the LCD
			GLCD_Clear(White);      // Clears the LCD with a white background

			GLCD_SetBackColor(Blue);    // Sets the LCD background color to blue
			GLCD_SetTextColor(Yellow);  // Sets the text color to yellow

			// Displays the lab title
			GLCD_DisplayString(
        0,
        0,
        __FI,
        (unsigned char *)" COE718 LAB 1 "
			);

			GLCD_SetTextColor(White);   // Changes text color to white

			// Displays the joystick demo title
			GLCD_DisplayString(
					1,
					0,
					__FI,
					(unsigned char *)" JOYSTICK DEMO "
			);

			GLCD_SetBackColor(White);   // Changes the background to white
			GLCD_SetTextColor(Blue);     // Changes the text color to blue

			// Displays the direction label
			GLCD_DisplayString(
					4,
					0,
					__FI,
					(unsigned char *)"Last Direction:"
			);

			// Displays the initial direction
			GLCD_DisplayString(
					6,
					0,
					__FI,
					(unsigned char *)"NONE"
			);

		#endif

		LED_Out(0);                 // Turns all LEDs off initially

		while (1)                   // Continuously monitors the joystick
		{
				joystick = get_button(); // Reads the current joystick input

				// Checks if the joystick is pointing UP
				if (joystick & KBD_UP)
				{
						LED_Out(1 << 0);     // Turns on LED 0

				#if __USE_LCD
										GLCD_ClearLn(6, __FI); // Clears the direction line

										// Displays UP on the LCD
										GLCD_DisplayString(
												6,
												0,
												__FI,
												(unsigned char *)"UP"
										);
				#endif
								}

								// Checks if the joystick is pointing RIGHT
								else if (joystick & KBD_RIGHT)
								{
										LED_Out(1 << 1);     // Turns on LED 1

				#if __USE_LCD
										GLCD_ClearLn(6, __FI); // Clears the direction line

										// Displays RIGHT on the LCD
										GLCD_DisplayString(
												6,
												0,
												__FI,
												(unsigned char *)"RIGHT"
										);
				#endif
								}

								// Checks if the joystick is pointing DOWN
								else if (joystick & KBD_DOWN)
								{
										LED_Out(1 << 2);     // Turns on LED 2

				#if __USE_LCD
										GLCD_ClearLn(6, __FI); // Clears the direction line

										// Displays DOWN on the LCD
										GLCD_DisplayString(
												6,
												0,
												__FI,
												(unsigned char *)"DOWN"
										);
				#endif
								}

								// Checks if the joystick is pointing LEFT
								else if (joystick & KBD_LEFT)
								{
										LED_Out(1 << 3);     // Turns on LED 3

				#if __USE_LCD
										GLCD_ClearLn(6, __FI); // Clears the direction line

										// Displays LEFT on the LCD
										GLCD_DisplayString(
												6,
												0,
												__FI,
												(unsigned char *)"LEFT"
										);
				#endif
								}

								// Checks if the joystick SELECT button is pressed
								else if (joystick & KBD_SELECT)
								{
										LED_Out(1 << 4);     // Turns on LED 4

				#if __USE_LCD
										GLCD_ClearLn(6, __FI); // Clears the direction line

										// Displays SELECT on the LCD
										GLCD_DisplayString(
												6,
												0,
												__FI,
												(unsigned char *)"SELECT"
										);
				#endif
        }
    }
}