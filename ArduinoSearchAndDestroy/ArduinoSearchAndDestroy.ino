#include "Arduino.h"
#include "TrackDriver.h"
#include "InitialiseIO.h"

#define FORWARD 0
#define LEFT 	1
#define RIGHT 	2

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(9600);
	int temp;
	if(( temp = initIO() ) != 0 ){
		Serial.println("Failure IO init");
	}

}


// The loop function is called in an endless loop
void loop() {



	int temp = movePattern( FORWARD );
	Serial.println(temp);
	delay(10000);

}
