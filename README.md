# Fan-Controller-System-using-ATmega16
Temperature-controlled fan using ATmega16 microcontroller in which the fan is automatically turned ON or OFF according to the temperature.
The LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it. This analog signal is given to the ADC, which converts the analog values to digital values. 
The digital output of the ADC is equivalent to sensed analog voltage. Convert the temperature to voltage using some calculations then the temperature is displayed on the LCD.
The microcontroller will continuously monitor the temperature and based on the temperature value, the microcontroller will drive the fan like that:
•	If the temperature is less than 30C turn off the fan.
•	If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed.
•	If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed.
•	If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed.
•	If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed.
The main principle of the circuit is to switch on/off the fan connected to DC motor basedon temperature value. The DC-Motor rotates in clock-wise direction or stopped based on the fan state.
