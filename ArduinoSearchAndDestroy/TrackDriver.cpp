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
	int state1 = 0;
	const int encoderInput = 6;
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

		photoEncoder( 6 );

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


//Counts revolutions of wheels using photoencoder
void photoEncoder(int encoderInput){

	int detectState1 = HIGH; // Variable for reading the encoder status
	int detectState2 = LOW; // Variable for reading the encoder status
	int state = 0;
	int numSlits = 0;

	switch (state) {

	case 0:

		if ((detectState1 = digitalRead(encoderInput)) == LOW) {
			state = 1;
		}
		break;

	case 1:

		if ((detectState2 = digitalRead(encoderInput)) == HIGH) {
			detectState1 = HIGH;
			detectState2 = LOW;
			state = 2;
		}

		break;

	case 2:
		if (++numSlits == 22) {
			Serial.println(numSlits);
			numSlits = 0;
		}
		state = 0;
		break;

	default:
		break;
	}
}

