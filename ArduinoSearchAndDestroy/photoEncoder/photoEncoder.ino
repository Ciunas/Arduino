
const int encoderInput = 8; // input pin for the interrupter
const int encoderDelayed = 8; // input pin for the interrupter
const int statusLED = 13; // Output pin for Status indicator
const int pulseOutput = 12; // Pulse output pin for external interfacing
int detectState1 = 0; // Variable for reading the encoder status
int detectState2 = 0; // Variable for reading the encoder status
int numSlits = 0;

void setup()
{

  Serial.begin(9600);
  pinMode(encoderInput, INPUT); //Set pin 8 as input
  pinMode(statusLED, OUTPUT); //Set pin 13 as output
  pinMode(pulseOutput, OUTPUT); // Set Pin 12 as output
}


void loop() {

  detectState1 = digitalRead(encoderInput);

  if (detectState1 == HIGH) { //If encoder output is high

    detectState2 = digitalRead(encoderInput);

    if (detectState2 == LOW) {

      digitalWrite(statusLED, HIGH); //Turn on the status LED
      numSlits++;
      Serial.println(numSlits);
      detectState1 = LOW;
      detectState2 = LOW;
    }

  }


}
