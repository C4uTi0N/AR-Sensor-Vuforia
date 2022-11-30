#include<Uduino.h>
Uduino uduino("Arduino Uno R3"); // Declare and name your object

int trigPin = 9;    // TRIG pin
int echoPin = 8;    // ECHO pin

float duration_us, distance_cm;


void setup()
{
  Serial.begin(9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);

  uduino.addCommand("readSensorValue", ReadSensor);
}

void ReadSensor() 
{  
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  uduino.delay(0.01);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  uduino.println(distance_cm);
}


void loop()
{
  uduino.update();
}
