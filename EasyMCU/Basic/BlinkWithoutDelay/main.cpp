#include "headers.h"


// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

int main()
{
	while (1) 
	{/* Loop forever */

		// here is where you'd put code that needs to be running all the time.

		// check to see if it's time to blink the LED; that is, if the 
		// difference between the current time and last time you blinked 
		// the LED is bigger than the interval at which you want to 
		// blink the LED.
		unsigned long currentMillis = timer.millis();
	 
		//if(timer.deltaTmillis(previousMillis) > interval)
		if(currentMillis - previousMillis > interval)
		{
			// save the last time you blinked the LED 
			previousMillis = currentMillis;   

			// if the LED is off turn it on and vice-versa:
			if(ledState == LOW)
				ledState = HIGH;
			else
				ledState = LOW;

			// set the LED with the ledState of the variable:
			io.write(LED2, ledState);
			//digitalWrite(LED2, ledState);
		}		
	} /* while */
} /* main */

