/******************************************************************************
 *
 * File Name: LM35_sensor.c
 *
 * Description: Source file for LM35 Temp sensor
 *
 * Author: John Emile
 *
 * Date : Oct 7, 2021
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "lcd.h"

uint8 LM35_getTemperature(void)
{
	uint16 adc_value = 0; /* To return the 10 bits of ADC */

	uint8 temp_value = 0; /* Temperature varies from 0 to 150 C so 8 bits are enough */

	adc_value = ADC_readChannel(LM35_SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value
	 * uint32 is to cast the numerator as it will be huge. "That's what she said"
	 * uint8 to cast the numerator after being divide by the denumerator.
	 * After division the number will fit in 8 bits only as the temperature varies from 0 to 150 C.
	 */
	temp_value = (uint8)(((uint32)adc_value*LM35_SENSOR_MAX_TEMP*ADC_MAX_OPERATING_VOLTAGE)/(LM35_SENSOR_MAX_OPERATING_VOLTAGE*ADC_MAX_DECIMAL_VALUE));

	return temp_value;

}

void LM35_displayTemperature (uint8 temperature)
{
	if(temperature >= 100)
			{
				LCD_intgerToString(temperature);
			}
			else
			{
				LCD_intgerToString(temperature);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
}
