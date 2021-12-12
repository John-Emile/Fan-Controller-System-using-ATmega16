/******************************************************************************
 *
 * File Name: motor.c
 *
 * Description: Source file for the DC Motor module.
 *
 * Author: John Emile
 *
 * Date : Oct 11, 2021
 *
 *******************************************************************************/

#include "motor.h"
#include "pwm_timer.h" /* To control the speed of fan */

void DCMOTOR_init(void)
{
	/* Setup the motor pins as output */
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID,DC_MOTOR_FIRST_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID,DC_MOTOR_SECOND_PIN_ID,PIN_OUTPUT);

	/* Stop the motor at the beginning */
	GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_FIRST_PIN_ID,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_SECOND_PIN_ID,LOGIC_LOW);
}

void DCMotor_Rotate(DcMotor_State state,uint8 speed)
{

	/* value to hold the corresponding duty cycle of the speed of fan
	 * Maximum potential value if speed = 100 -> 25600
	 * 25600 fit in uint16 (65535)
	 * Duty_cycle --> Speed
	 * 255 --> 100 (max)
	 * ?? --> Speed
	 */
	uint16 fan_duty_cycle = speed*255/100;

	/* Initialize timer and pwm driver */
	TIMER_ConfigType configuration = { TIMER1_ID,TIMER1_MODE_FAST_PWM_OCR1A,0,255,TIMER_CLOCK_CPU_64};
	TIMER_init(&configuration);

	PWM_ConfigType configuration2 = { TIMER1_ID,PWM_MODE_NON_INVERTING,PWM_CLOCK_CPU_64,fan_duty_cycle};
	PWM_Timer_start(&configuration2);

	/* Stop or rotate based on the state */
	switch(state)
	{
	case DC_MOTOR_STOP :
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_FIRST_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_SECOND_PIN_ID,LOGIC_LOW);
		break;
	case DC_MOTOR_CLOCKWISE :
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_FIRST_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_SECOND_PIN_ID,LOGIC_HIGH);
		break;
	case DC_MOTOR_ANTI_CLOCKWISE :
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_FIRST_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_SECOND_PIN_ID,LOGIC_LOW);
		break;
	}
}
