
#include "headers.h"

// constants won't change. They're used here to 
// set pin numbers:
#define buttonPin  P5     // the number of the pushbutton pin

// variables will change:
int buttonState = LOW;         // variable for reading the pushbutton status

int main()
{
	// initialize the LED pin as an output: LEDs by default config as output
	io.mode(LED1, OUTPUT);  
   
	// initialize the pushbutton pin as an input:
	io.mode(buttonPin, INPUT);		
	//pinMode(buttonPin, INPUT); 
	
	while (1) 
	{/* Loop forever */
		// read the state of the pushbutton value:
		buttonState = io.read(buttonPin);
		//buttonState = digitalRead(buttonPin);

		// check if the pushbutton is pressed.
		// if it is, the buttonState is HIGH:
		if (buttonState == HIGH) {     
			// turn LED on: 
			io.reset(LED1);				// LEDs of Zcross V1 are active low : 0 -> ON , 1 -> OFF
			//io.write(LED1, LOW);		// Another method
			//digitalWrite(LED1, LOW);  // Arduino style 
		} 
		else
		{
			// turn LED off:
			io.set(LED1);				// LEDs of Zcross V1 are active low : 0 -> ON , 1 -> OFF
			io.write(LED1, HIGH);		// Another method
			//digitalWrite(LED1, HIGH); // Arduino style
		}		
	} /* while */
} /* main */
