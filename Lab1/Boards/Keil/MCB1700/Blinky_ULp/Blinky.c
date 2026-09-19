/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: COE718 Lab 1 - Joystick controlled LCD and LEDs
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>
#include "Blinky.h"
#include "LPC17xx.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
/*
 * Font index used by the LCD.
 */
#define __FI 1

/*
 * LCD OPTION
 * 1 = LCD enabled
 * 0 = LCD disabled
 * Set to 0 while using Debug mode.
 * Set to 1 for the normal Lab 1 demonstration.
 */
#define __USE_LCD 1
/*----------------------------------------------------------------------------
 * Main Program
 *----------------------------------------------------------------------------*/
int main(void)
{
    /*
     * Stores the value returned by get_button().
     * get_button() reads the physical joystick through
     * the GPIO pins configured in KBD.c.
     */
    uint32_t joystick;
    /*
     * Stores the last joystick direction.
     * This allows the program to remember the last direction
     * after the joystick is released.
     */
    uint32_t last_direction = 0;
    /*-----------------------------------------------------------------------
     * Initialize LEDs
     *-----------------------------------------------------------------------*/
    LED_Init();
    /*-----------------------------------------------------------------------
     * Initialize Joystick
     *-----------------------------------------------------------------------*/
    KBD_Init();
		#if __USE_LCD

				/*-----------------------------------------------------------------------
				 * Initialize LCD
				 *-----------------------------------------------------------------------*/
				GLCD_Init();
				GLCD_Clear(White);

				/*
				 * Display Lab 1 title.
				 */
				GLCD_SetBackColor(Blue);
				GLCD_SetTextColor(Yellow);
				GLCD_DisplayString(
						0,
						0,
						__FI,
						(unsigned char *)"     COE718 LAB 1    "
				);
				/*
				 * Display subtitle.
				 */
				GLCD_SetTextColor(White);

				GLCD_DisplayString(
						1,
						0,
						__FI,
						(unsigned char *)"   JOYSTICK DEMO     "
				);
				/*
				 * Display direction label.
				 */
				GLCD_SetBackColor(White);
				GLCD_SetTextColor(Blue);

				GLCD_DisplayString(
						4,
						0,
						__FI,
						(unsigned char *)"Last Direction:"
				);
				/*
				 * Initially no direction has been pressed.
				 */
				GLCD_DisplayString(
						6,
						0,
						__FI,
						(unsigned char *)"NONE                "
				);

		#endif
    /*
     * Initially turn all LEDs off.
     */
    LED_Out(0);
    /*-----------------------------------------------------------------------
     * Main Joystick Loop
     *-----------------------------------------------------------------------*/
    while (1)
    {
			joystick = get_button();
        /*-------------------------------------------------------------------
         * UP
         *-------------------------------------------------------------------*/

        if (joystick & KBD_UP)
        {
            /*
             * Remember that UP was the last direction pressed.
             */
            last_direction = KBD_UP;


            /*
             * LED 0 represents UP.
             */
            LED_Out(1 << 0);


				#if __USE_LCD

										/*
										 * Display UP on the LCD.
										 */
										GLCD_DisplayString(
												6,
												0,
												__FI,
												(unsigned char *)"UP                  "
										);

				#endif
								}


								/*-------------------------------------------------------------------
								 * RIGHT
								 *-------------------------------------------------------------------*/

								else if (joystick & KBD_RIGHT)
								{
										/*
										 * Remember that RIGHT was the last direction pressed.
										 */
										last_direction = KBD_RIGHT;


										/*
										 * LED 1 represents RIGHT.
										 */
										LED_Out(1 << 1);


				#if __USE_LCD

										/*
										 * Display RIGHT on the LCD.
										 */
										GLCD_DisplayString(
												6,
												0,
												__FI,
												(unsigned char *)"RIGHT               "
										);
				#endif
								}


								/*-------------------------------------------------------------------
								 * DOWN
								 *-------------------------------------------------------------------*/

								else if (joystick & KBD_DOWN)
								{
										/*
										 * Remember that DOWN was the last direction pressed.
										 */
										last_direction = KBD_DOWN;


										/*
										 * LED 2 represents DOWN.
										 */
										LED_Out(1 << 2);


					#if __USE_LCD

											/*
											 * Display DOWN on the LCD.
											 */
											GLCD_DisplayString(
													6,
													0,
													__FI,
													(unsigned char *)"DOWN                "
											);

					#endif
									}


									/*-------------------------------------------------------------------
									 * LEFT
									 *-------------------------------------------------------------------*/

									else if (joystick & KBD_LEFT)
									{
											/*
											 * Remember that LEFT was the last direction pressed.
											 */
											last_direction = KBD_LEFT;


											/*
											 * LED 3 represents LEFT.
											 */
											LED_Out(1 << 3);


					#if __USE_LCD

											/*
											 * Display LEFT on the LCD.
											 */
											GLCD_DisplayString(
													6,
													0,
													__FI,
													(unsigned char *)"LEFT                "
											);

					#endif
									}


									/*-------------------------------------------------------------------
									 * SELECT
									 *-------------------------------------------------------------------*/

									else if (joystick & KBD_SELECT)
									{
											/*
											 * SELECT is provided by the KBD driver.
											 *
											 * We give SELECT its own LED and LCD indication.
											 */
											last_direction = KBD_SELECT;


											/*
											 * LED 4 represents SELECT.
											 */
											LED_Out(1 << 4);


					#if __USE_LCD

											/*
											 * Display SELECT on the LCD.
											 */
											GLCD_DisplayString(
													6,
													0,
													__FI,
													(unsigned char *)"SELECT              "
											);

					#endif
        }
        /*
         * There is intentionally NO "else" here.
         * When the joystick is released, joystick becomes 0.
         * Since none of the conditions are true
         *   - the LED remains showing the last direction
         *   - the LCD remains showing the last direction
         * This satisfies the lab requirement that the LCD display
         * the LAST direction the joystick was tilted/pressed.
         */
    }
}