/*----------------------------------------------------------------------------
 * Name:    IRQ.c
 * Purpose: COE718 Lab 1 interrupt handler
 *
 * The original Blinky program used SysTick for the ADC and
 * automatic LED blinking.
 *
 * Lab 1 does not require the ADC or automatic LED blinking.
 * The joystick is read directly in Blinky.c.
 *----------------------------------------------------------------------------*/

#include "LPC17xx.h"


/*----------------------------------------------------------------------------
 * SysTick Interrupt Handler
 *
 * ADDED:
 * We do not need SysTick for the joystick implementation.
 * The joystick is continuously checked inside main().
 *----------------------------------------------------------------------------*/

void SysTick_Handler(void)
{
    /*
     * Nothing is required here for Lab 1.
     */
}