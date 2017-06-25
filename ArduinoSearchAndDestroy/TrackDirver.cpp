/*
 * Ciunas Bennett
 *
 *  Created on: 23 Jun 2017
 *  
 */

#include "Arduino.h"

int movePattern(int state) {

	Serial.println("New instance");
	int detectState1 = 0; // Variable for reading the encoder status
	int detectState2 = 0; // Variable for reading the encoder status
	int numSlits = 0;
	int rightFront = 2;
	int rightBack = 3;
	int leftFront = 4;
	int leftBack = 5;

//	digitalWrite(2, LOW); // turn the LED on (HIGH is the voltage level)
//	digitalWrite(3, HIGH); // turn the LED on (HIGH is the voltage level)
//
//	digitalWrite(leftFront, HIGH); // turn the LED on (HIGH is the voltage level)
//	digitalWrite(leftBack, LOW);

	while (numSlits < state) {
		detectState1 = digitalRead(6);

		if (detectState1 == 1) { //If encoder output is high

			detectState2 = digitalRead(6);

			if (detectState2 == 0) {

				digitalWrite(13, 1); //Turn on the status LED
				numSlits++;
				//Serial.println(numSlits);
			detectState1 = 0;
			detectState2 = 0;
			}
		}

	}

	return numSlits;
}

