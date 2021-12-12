
#ifndef ADC_H_
#define ADC_H_

#include "common_macros.h"
#include "std_types.h"

/*******************************************************************************
 * 								Definitions									   *
 *******************************************************************************/
#define ADC_MAX_OPERATING_VOLTAGE 		2.56
#define ADC_MAX_DECIMAL_VALUE			1023

/*******************************************************************************
 *                    		  	Enumerations                                   *
 *******************************************************************************/
typedef enum {
ADC_CHANNEL_ZERO_ID , ADC_CHANNEL_ONE_ID , ADC_CHANNEL_TWO_ID , ADC_CHANNEL_THREE_ID,
ADC_CHANNEL_FOUR_ID , ADC_CHANNEL_FIVE_ID , ADC_CHANNEL_SIX_ID , ADC_CHANNEL_SEVEN_ID
}ADC_Channel;


typedef enum {
	ADC_PRESCALER_DIVISION_FACTOR_2 = 1 , ADC_PRESCALER_DIVISION_FACTOR_4
	, ADC_PRESCALER_DIVISION_FACTOR_8 , ADC_PRESCALER_DIVISION_FACTOR_16 , ADC_PRESCALER_DIVISION_FACTOR_32
	, ADC_PRESCALER_DIVISION_FACTOR_64 ,ADC_PRESCALER_DIVISION_FACTOR_128
}ADC_Prescaler;

/* Enum that has the reference voltage of ADC Module */
typedef enum {
	ADC_AREF_VOLTAGE , ADC_AVCC_VOLTAGE , ADC_INTERNAL_VOLTAGE = 3
}ADC_ReferenceVolatge;

/*******************************************************************************
 *                    		    	Structures                                 *
 *******************************************************************************/
/* Struct that will control the dynamic configuration */
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                    		  Functions Prototypes                             *
 *******************************************************************************/

/* Initialize the ADC module */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/* Read the channel number and send the data */
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
