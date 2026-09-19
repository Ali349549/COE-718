/*----------------------------------------------------------------------------
 * Name:    LED.c
 * Purpose: low level LED functions
 *----------------------------------------------------------------------------*/

#include "LPC17xx.h"
#include "LED.h"


const unsigned long led_mask[] = {
    1UL << 28,
    1UL << 29,
    1UL << 31,
    1UL << 2,
    1UL << 3,
    1UL << 4,
    1UL << 5,
    1UL << 6
};


/*----------------------------------------------------------------------------
 * Initialize LED Pins
 *----------------------------------------------------------------------------*/

void LED_Init(void)
{
    /*
     * Enable power to GPIO and IOCON.
     */
    LPC_SC->PCONP |= (1 << 15);

    /*
     * LEDs on PORT1 are outputs.
     */
    LPC_GPIO1->FIODIR |= 0xB0000000;

    /*
     * LEDs on PORT2 are outputs.
     */
    LPC_GPIO2->FIODIR |= 0x0000007C;
}


/*----------------------------------------------------------------------------
 * Turn on requested LED
 *----------------------------------------------------------------------------*/

void LED_On(unsigned int num)
{
    if (num < 3)
        LPC_GPIO1->FIOPIN |= led_mask[num];
    else
        LPC_GPIO2->FIOPIN |= led_mask[num];
}


/*----------------------------------------------------------------------------
 * Turn off requested LED
 *----------------------------------------------------------------------------*/

void LED_Off(unsigned int num)
{
    if (num < 3)
        LPC_GPIO1->FIOPIN &= ~led_mask[num];
    else
        LPC_GPIO2->FIOPIN &= ~led_mask[num];
}


/*----------------------------------------------------------------------------
 * Output value to LEDs
 *----------------------------------------------------------------------------*/

void LED_Out(unsigned int value)
{
    int i;

    for (i = 0; i < LED_NUM; i++)
    {
        if (value & (1 << i))
            LED_On(i);
        else
            LED_Off(i);
    }
}