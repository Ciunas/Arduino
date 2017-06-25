/*
 * Ciunas Bennett
 *
 *  Created on: 25 Jun 2017
 *  
 */
#include "Arduino.h"

int initIO(){


	//Set output pins for track and
	for(int i=2; i<6; i++){
		pinMode(i, OUTPUT);
	}
	//set input for photodiode
	pinMode(6, INPUT);

	return 0;
}


