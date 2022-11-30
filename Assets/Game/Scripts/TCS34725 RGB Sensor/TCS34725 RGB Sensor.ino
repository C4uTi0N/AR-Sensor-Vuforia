//Libraries
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include<Uduino.h>

Uduino uduino("Arduino Uno R3"); // Declare and name your object

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_600MS, TCS34725_GAIN_1X);

float r;
float g;
float b;

String curColor;

void setup(void) {
Serial.begin(9600);
 
if (tcs.begin()) {
Serial.println("Found sensor");
} else {
Serial.println("No TCS34725 found ... check your connections");
while (1);
}
 

// Now we're ready to get readings!
}

 void loop() {
   ReadColorData();
 }

void ReadColorData() {
  uint16_t r, g, b, c, colorTemp, lux;
 
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);

  float sum = r + g + b;
  //Serial.println(sum);
  
  float rP = (r/sum)*100;
  float gP = (g/sum)*100;
  float bP = (b/sum)*100;
  //Serial.println(rP + gP + bP);

  if(rP > gP && rP > bP) {
    Serial.println("red");
  }
  else if(gP > rP && gP > bP) {
    Serial.println("green");
  }
  else if (bP > rP && bP > gP) {
    Serial.println("blue");
  }
  else {
    Serial.println("Color unidentified");
  }
  /*Serial.println("R procent:");
  Serial.println(rP);
  Serial.println("G procent:");
  Serial.println(gP);
  Serial.println("B procent:");
  Serial.println(bP);*/
/*
  if (rP >= 16.89 && rP <= 19.17 && gP >= 36.87 && gP <= 39.04 && bP >= 42.95 && bP <= 45.07) {
    Serial.println("Blue");
    curColor = ("Blue");
  }

  else if (rP >= 33.41 && rP <= 35.51 && gP >= 41.90 && gP <= 44.07 && bP >= 21.50 && bP <= 23.58) {
    Serial.println("Lightgreen");
    curColor = ("Lightgreen");
  }

  else if (rP >= 23.60 && rP <= 25.67 && gP >= 45.26 && gP <= 47.43 && bP >= 27.96 && bP <= 30.07) {
    Serial.println("Darkgreen");
    curColor = ("Darkgreen");
  }

  else if (rP >= 50.79 && rP <= 52.91 && gP >= 20.08 && gP <= 22.14 && bP >= 26.01 && bP <= 28.07) {
    Serial.println("Pink");
    curColor = ("Pink");
  }

  else if (rP >= 40.15 && rP <= 42.63 && gP >= 37.53 && gP <= 39.97 && bP >= 18.81 && bP <= 20.88) {
    Serial.println("Yellow");
    curColor = ("Yellow");
  }

  else if (rP >= 39.10 && rP <= 41.13 && gP >= 33.38 && gP <= 35.40 && bP >= 24.49 && bP <= 26.51) {
    Serial.println("Beige");
    curColor = ("Beige");
  }

  else if (rP >= 67.47 && rP <= 69.49 && gP >= 14.04 && gP <= 16.05 && bP >= 15.47 && bP <= 17.49) {
    Serial.println("Red");
    curColor = ("Red");
  }

  else if (rP >= 56.42 && rP <= 59.66 && gP >= 24.92 && gP <= 27.94 && bP >= 14.42 && bP <= 16.64) {
    Serial.println("Orange");
    curColor = ("Orange");
  }

  else if (rP >= 46.14 && rP <= 48.32 && gP >= 27.83 && gP <= 29.94 && bP >= 22.86 && bP <= 24.92) {
    Serial.println("Brown");
    curColor = ("Brown");
  }
 */
  /*Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");*/
  
}
