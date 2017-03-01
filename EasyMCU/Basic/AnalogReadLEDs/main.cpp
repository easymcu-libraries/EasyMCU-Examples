#include "headers.h"

/*
  AnalogReadLEDs
  Attach the center pin of a potentiometer to pin P5, and the outside pins to +3.3V and ground.
 
 This example code is in the public domain.
 */

int main()
{
	// the setup routine runs once when you press reset:
	// Define a variable to keep analog value
	uint32_t sensorValue;

	// don't need to config board's LEDs, they configured as output at startUp by default.
	// if use USB CDC don't need to init/begin serial comunication, it will run by itself at start Up

	// the loop routine runs over and over again forever:
	while (1) 
	{/* Loop forever */
		// read the input on analog pin P5:
		sensorValue = adc.read(CH6);
		//sensorValue = analogRead(CH6);
		// by default analogRead have 12bits of ADC(Analog to Digital Converter) value
		// Zcross have 4 LED, so we can show just 4 bit to 4 LED of Zcross board.
		// so we need just 4 more significant bits, then shift its value 8 times to right
		sensorValue = sensorValue >> 8;

		// Show value read on boars's LEDs:			
		io.portWrite(sensorValue,P1,P2,P3,P4);

		delay.ms(100);        // delay in between reads for stability
		
	} /* while */
} /* main */

