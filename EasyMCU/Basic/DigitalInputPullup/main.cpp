#include "headers.h"


int main()
{
	io.mode(P5, INPUT_PULLUP);
	//pinMode(P5, INPUT_PULLUP);
	//following line defined as output by default at Start Up
	//pinMode(P1, OUTPUT);

	while (1) 
	{/* Loop forever */
		//read the pushbutton value into a variable
		uint32_t keyVal = io.read(P5);
		//uint32_t keyVal = digitalRead(P5);
		//print out the value of the pushbutton
		cdc.println(keyVal);
		
		// Keep in mind the pullup means the pushbutton's
		// logic is inverted. It goes HIGH when it's open,
		// and LOW when it's pressed. Turn on the pin when the 
		// button's pressed, and off when it's not:
		if (keyVal == LOW)
		{
			io.reset(P1);
			//io.write(P1, LOW);
			//digitalWrite(P1, LOW);
		} 
		else
		{
			io.set(P1);
			//io.write(P1, HIGH);
			//digitalWrite(P1, HIGH);
		}			
	} /* while */
} /* main */

