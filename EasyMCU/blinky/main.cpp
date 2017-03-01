#include "headers.h"



int main()
{
	// initialize the digital pin as an output.
	// pinMode(LED1, OUTPUT); 
	// LEDs of Zcross are configured as output by default at start Up

	// the loop routine runs over and over again forever:		
	while (1) 
	{/* Loop forever */
		
		//io.toggle(LED1);

		//io.write(LED1, HIGH);				// turn the LED on (HIGH is the voltage level)
		io.set(LED1);
		//digitalWrite(LED1, HIGH); 
		
		delay.ms(1000);               		// wait for a second
		
		//io.write(LED1, LOW);    			// turn the LED off by making the voltage LOW
		io.reset(LED1);
		//digitalWrite(LED1, LOW); 	
		
		delay.ms(1000);  
				
	} /* while */
} /* main */
