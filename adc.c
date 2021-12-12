#include "adc.h"

/* To use ADC registers */
#include <avr/io.h>


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/* Initialization using dynamic configuration */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 to be inserted
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization, won't matter as we don't read from the init function.
	 * ADMUX &3F to clear the 2 MSB and preserve the other bits
	 * <<6 to get bit 0 to be @6 + bit 1 to be @ 7 for REFS 1:0
	 */

	/* Insert the Reference voltage bits */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);

	/* ADCSRA Register Bits Description:
	 * ADEN = 1 -> Enable ADC
	 */
	ADCSRA = (1<<ADEN);

	/* Insert the Pre-scaler bits
	 * Clear the 3 LSB
	 */
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler);

}

uint16 ADC_readChannel (uint8 ch_num)
{
	/* Insert the channel number in ADMUX register
	 * Clear The LSB 5 bits and preserve the MSB as they can be used for other purpose (don't overwrite them)
	 * ADMUX & 1110 0000 (E0) = Preserve the MSB 3 bits and clear the rest
	 */
	ADMUX = (ADMUX & 0xE0 ) | (ch_num & 0x07);

	/* Start conversion */
	SET_BIT(ADCSRA,ADSC);

	/* Wait until ADIF = 1 (Interrupt flag is set) -> Polling technique */
	while (BIT_IS_CLEAR(ADCSRA,ADIF));

	/* Clear the flag by writing 1 to it*/
	SET_BIT(ADCSRA,ADIF);

	/*Return the digital value of ADC register which contains our 10 bits*/
	return ADC;

}
