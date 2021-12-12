/******************************************************************************
 *
 * File Name: application.c
 *
 * Description: Fan Controller system which fan is automatically turned ON or
 * 				OFF according to the temperature.
 *
 * Author: John Emile
 *
 * Date : Oct 11, 2021
 *
 *******************************************************************************/

#include "motor.h"
#include "lcd.h"
#include "lm35_sensor.h"

int main(void)
{
	/* To hold the value returned from the sensor by ADC */
	uint8 temperature = 0;
	uint8 speed = 0;

	/* Struct with name adc_configuration with type ADC_ConfigType to hold ADC module desirable configuration */
	ADC_ConfigType adc_configuration = { ADC_INTERNAL_VOLTAGE , ADC_PRESCALER_DIVISION_FACTOR_8 };

	/* Initialization of modules */
	LCD_init();
	ADC_init(&adc_configuration);
	DCMOTOR_init();

	/* Display only once */
	LCD_displayStringRowColumn(0,3,"FAN IS ");

	/* Move cursor to the second row */
	LCD_moveCursor(1,3);
	LCD_displayString("TEMP =     C");

	for(;;)
	{
		/* Get the value from the sensor and display on LCD */
		temperature = LM35_getTemperature();

		LCD_moveCursor(1,10);
		LM35_displayTemperature(temperature);

		if (temperature<30)
		{
			/* Fan State */
			LCD_displayStringRowColumn(0,10,"OFF");

			/* Set speed based on the temperature,Send it to motor. */
			speed = 0;
			DCMotor_Rotate(DC_MOTOR_STOP,speed);
		}

		else if ( (temperature>=30) && (temperature<60) )
		{
			/* Show the fan state */
			LCD_displayStringRowColumn(0,10,"ON ");

			/* Set speed based on the temperature,Send it to motor. */
			speed = 25;
			DCMotor_Rotate(DC_MOTOR_CLOCKWISE,speed);
		}

		else if ( (temperature>=60) && (temperature<90) )
		{
			/* Show the fan state */
			LCD_displayStringRowColumn(0,10,"ON ");

			/* Set speed based on the temperature,Send it to motor. */
			speed = 50;
			DCMotor_Rotate(DC_MOTOR_CLOCKWISE,speed);
		}

		else if ( (temperature>=90) && (temperature<120) )
		{
			/* Show the fan state */
			LCD_displayStringRowColumn(0,10,"ON ");

			/* Set speed based on the temperature,Send it to motor. */
			speed = 75;
			DCMotor_Rotate(DC_MOTOR_CLOCKWISE,speed);
		}
		else if ((temperature>=120) && (temperature<=150)) /* LM35 has a maximum of 150C */
		{
			/* Show the fan state */
			LCD_displayStringRowColumn(0,10,"ON ");

			/* Set speed based on the temperature,Send it to motor. */
			speed = 100;
			DCMotor_Rotate(DC_MOTOR_CLOCKWISE,speed);
		}
	}
}
