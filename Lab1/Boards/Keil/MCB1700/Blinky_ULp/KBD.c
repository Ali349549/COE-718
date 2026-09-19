/*----------------------------------------------------------------------------
 * Name:    KBD.c
 * Purpose: MCB1700 low level Joystick
 * Version: V2.0
 *----------------------------------------------------------------------------*/

#include <LPC17xx.H>
#include "KBD.h"

uint32_t KBD_val = 0;


/*----------------------------------------------------------------------------
 * Initialize Joystick
 *----------------------------------------------------------------------------*/

void KBD_Init(void)
{
    /*
     * Enable power to GPIO and IOCON.
     */
    LPC_SC->PCONP |= (1 << 15);


    /*
     * P1.20, P1.23, P1.24, P1.25 and P1.26
     * are used as GPIO pins for the joystick.
     */
    LPC_PINCON->PINSEL3 &= ~((3 << 8) |
                             (3 << 14) |
                             (3 << 16) |
                             (3 << 18) |
                             (3 << 20));


    /*
     * Configure joystick pins as inputs.
     */
    LPC_GPIO1->FIODIR &= ~((1 << 20) |
                           (1 << 23) |
                           (1 << 24) |
                           (1 << 25) |
                           (1 << 26));
}


/*----------------------------------------------------------------------------
 * Get Joystick value
 *----------------------------------------------------------------------------*/

uint32_t KBD_get(void)
{
    uint32_t kbd_val;

    /*
     * Read GPIO1.
     *
     * Shift right by 20 so the joystick bits line up
     * with the KBD_MASK definitions in KBD.h.
     */
    kbd_val = (LPC_GPIO1->FIOPIN >> 20) & KBD_MASK;

    return kbd_val;
}


/*----------------------------------------------------------------------------
 * Get Joystick value with active-low conversion
 *----------------------------------------------------------------------------*/

uint32_t get_button(void)
{
    uint32_t val = 0;

    /*
     * Read the joystick.
     */
    val = KBD_get();

    /*
     * Joystick buttons are active-low.
     *
     * This changes a pressed joystick position into a
     * non-zero value.
     */
    val = (~val & KBD_MASK);

    return val;
}