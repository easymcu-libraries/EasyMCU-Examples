
#include "headers.h"


#define buttonPin 	P5
#define ledPin		P1

uint8_t	ledState = LOW;
// Variables will change:
uint32_t buttonState;             // the current reading from the input pin
uint32_t lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long debounceDelay = 90;    // the debounce time; increase if the output flickers


int main()
{
	int reading;
	io.mode(buttonPin, INPUT);
	//pinMode(buttonPin, INPUT);
	io.mode(ledPin, OUTPUT);
	//pinMode(ledPin, OUTPUT);

	// set initial LED state
	io.mode(ledPin, ledState);
	//digitalWrite(ledPin, ledState);

	while (1) 
	{/* Loop forever */

		// read the state of the switch into a local variable:
		reading = io.read(buttonPin);
		//reading = digitalRead(buttonPin);
		
		if(reading)
		{
			delay.ms(debounceDelay);
			//delay(debounceDelay);
			if(reading)
			{
				io.reset(ledPin);
				//io.write(ledPin, LOW);
				//digitalWrite(ledPin, LOW);
			}
			else
			{
				io.set(ledPin);
				//io.write(ledPin, HIGH);
				//digitalWrite(ledPin, HIGH);							
			}
		}
		else
		{
			io.set(ledPin);
			//io.write(ledPin, HIGH);
			//digitalWrite(ledPin, HIGH);					
		}
	} /* while */
} /* main */
