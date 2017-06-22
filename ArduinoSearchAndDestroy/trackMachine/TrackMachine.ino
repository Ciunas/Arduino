
int rightFront = 2;
int rightBack = 3;
int leftFront = 4;
int leftBack = 5;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(rightFront, OUTPUT); 
  pinMode(rightBack, OUTPUT);  
  pinMode(leftFront, OUTPUT);  
  pinMode(leftBack, OUTPUT);  
  Serial.begin(9600);


}

// the loop routine runs over and over again forever:
void loop() {
    Serial.println("It has Begun");
digitalWrite(rightFront, HIGH);   // turn the LED on (HIGH is the voltage level)
digitalWrite(rightBack, LOW);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(leftFront, LOW);   // turn the LED on (HIGH is the voltage level)
digitalWrite(leftBack, LOW);
  delay(1000);               // wait for a second
digitalWrite(leftFront, HIGH);   // turn the LED on (HIGH is the voltage level)
digitalWrite(leftBack, LOW);   // turn the LED on (HIGH is the voltage level
 
 digitalWrite(rightFront, LOW);   // turn the LED on (HIGH is the voltage level)
digitalWrite(rightBack, LOW);   // turn the LED on (HIGH is the voltage level)
 delay(1000);  

}

