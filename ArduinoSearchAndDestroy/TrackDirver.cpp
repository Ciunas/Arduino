/*
 * Ciunas Bennett
 *
 *  Created on: 23 Jun 2017
 *  
 */

#include "Arduino.h"
#define FORWARD 0
#define LEFT 	1
#define RIGHT 	2
#define STOP 	3

int movePattern(int state) {

	Serial.println("New instance");
	int detectState1 = 0; // Variable for reading the encoder status
	int detectState2 = 0; // Variable for reading the encoder status
	int numSlits = 0;
	int rightFront = 2;
	int rightBack = 3;
	int leftFront = 4;
	int leftBack = 5;
	digitalWrite(13, 0);
//	digitalWrite(2, LOW); // turn the LED on (HIGH is the voltage level)
//	digitalWrite(3, HIGH); // turn the LED on (HIGH is the voltage level)
//
//	digitalWrite(leftFront, HIGH); // turn the LED on (HIGH is the voltage level)
//	digitalWrite(leftBack, LOW);

	switch (state) {

	case FORWARD:

		digitalWrite(rightFront, LOW); // turn on the tracks
		digitalWrite(rightBack, HIGH);

		while ( numSlits < 50 ) {
			detectState1 = digitalRead(6);

			if (detectState1 == 1) { //If encoder output is high
				Serial.println(numSlits);
				detectState2 = digitalRead(6);

				if (detectState2 == 0) {
					//Serial.println(numSlits);
					digitalWrite(13, 1); //Turn on the status LED
					numSlits++;
					detectState1 = 0;
					detectState2 = 0;
				}
			}

		}
		state = STOP;
		break;

	case LEFT:

		break;

	case RIGHT:

		break;

	case STOP:					//Stop all tracks
		digitalWrite(rightFront, LOW);
		digitalWrite(rightBack, LOW);
		digitalWrite(leftFront, LOW);
		digitalWrite(leftBack, LOW);
		break;

	default:
		digitalWrite(rightFront, LOW);
		digitalWrite(rightBack, LOW);
		digitalWrite(leftFront, LOW);
		digitalWrite(leftBack, LOW);
		break;

	}

	return numSlits;
}

