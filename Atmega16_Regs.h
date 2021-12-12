/*
 ============================================================================
 Name        : Atmega16_Regs.h
 Author      : John Emile
 Description : Header file for ATmega16 Registers Declaration
 Date        : 28/9/2021
 ============================================================================
 */

#ifndef ATMEGA16_REGS_H_
#define ATMEGA16_REGS_H_

#include "Std_Types.h"

/* Definition for PORTA Registers */
#define PORTA	(*(volatile uint8 * const)0x003B)
#define DDRA	(*(volatile uint8 * const)0x003A)
#define PINA 	(*(volatile const uint8 * const)0x0039) /*Read only so constant pointer to constant data*/

/* Definition for PORTB Registers */
#define PORTB	(*(volatile uint8 * const)0x0038)
#define DDRB	(*(volatile uint8 * const)0x0037)
#define PINB 	(*(volatile const uint8 * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC	(*(volatile uint8 * const)0x0035)
#define DDRC	(*(volatile uint8 * const)0x0034)
#define PINC 	(*(volatile const uint8 * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD	(*(volatile uint8 * const)0x0032)
#define DDRD	(*(volatile uint8 * const)0x0031)
#define PIND 	(*(volatile const uint8 * const)0x0030)

#endif /* ATMEGA16_REGS_H_ */
