
#include <Servo.h>

const int pingPin = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 3; // Echo Pin of Ultrasonic Sensor
const int pingPin2 = 5; // Trigger2 Pin of Ultrasonic Sensor
const int echoPin2 = 6; // Echo2 Pin of Ultrasonic Sensor
//servo 1 = 7
Servo servoright; // pin 7
Servo servoleft; // pin8
void setup() {

   Serial.begin(9600); // Starting Serial Terminal
   servoright.attach(7);
 servoleft.attach(8);
}

void loop() {
   long duration, inches, cm;
   long duration2, inches2, cm2;

// sensor 2
    pinMode(pingPin2, OUTPUT);
    digitalWrite(pingPin2, LOW);
    delayMicroseconds(2);
     
    digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
 
    pinMode(echoPin2, INPUT);
   duration2 = pulseIn(echoPin2, HIGH);
   inches2 = microsecondsToInches(duration2);
   cm2 = microsecondsToCentimeters(duration2);

   //sensor 2
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  digitalWrite(pingPin, HIGH);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

if (cm <= 4){
servoright.write(0); //makes the rover move in a continuous straight line
  servoleft.write(180);

 if(cm >=3){
servoright.write(60);  //makes the rover turn in a circle so as to look for the path again
servoleft.write(60);
  }

}

else{
servoright.write(180); //makes the rover move in a continuous straight line
servoleft.write(0);
} 


if (cm2 <7){
servoright.write(60);  //makes the rover turn in a circle so as to look for the path again
servoleft.write(60);
}

  Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
Serial.println();

   Serial.print(inches2);
   Serial.print("in2, ");
      Serial.print(cm2);
   Serial.print("cm2");
   Serial.println();
  delay(100);

}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

