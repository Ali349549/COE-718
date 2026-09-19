/*----------------------------------------------------------------------------
 * Name:    LED.h
 * Purpose: low level LED definitions
 *----------------------------------------------------------------------------*/

#ifndef __LED_H
#define __LED_H

/* LED Definitions */
#define LED_NUM     8

extern void LED_Init(void);
extern void LED_On(unsigned int num);
extern void LED_Off(unsigned int num);
extern void LED_Out(unsigned int value);

#endif