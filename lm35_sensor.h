/******************************************************************************
 *
 * File Name: LM35_sensor.h
 *
 * Description: Header file for LM35 Temp sensor
 *
 * Author: John Emile
 *
 * Date : Oct 7, 2021
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/* To use the channel id definition in the header file
 * also it will be used in the source file in the return equation for adc values
 * like adc max operating voltage */

#include "adc.h"

#include "std_types.h"
/*******************************************************************************
 * 								Definitions									   *
 *******************************************************************************/

#define LM35_SENSOR_MAX_OPERATING_VOLTAGE 		1.5
#define LM35_SENSOR_MAX_TEMP 					150
#define LM35_SENSOR_CHANNEL_ID 					ADC_CHANNEL_TWO_ID

/*******************************************************************************
 *							 Functions Prototypes 							   *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */

uint8 LM35_getTemperature(void);

void LM35_displayTemperature(uint8 Temperature);

#endif /* LM35_SENSOR_H_ */
