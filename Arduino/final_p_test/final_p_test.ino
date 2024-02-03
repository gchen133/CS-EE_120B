//#include "Timer.h"
#include "Stepper.h"


int stepperSpeed = 10;

Stepper Stepper_1(2048, 8, 10, 9, 11);
Stepper Stepper_2(2048, 4, 6, 5, 7);

void setup() {
  // put your setup code here, to run once:
  Stepper_1.setSpeed(stepperSpeed);
  Stepper_2.setSpeed(stepperSpeed);
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  bool buttonPressed = digitalRead(2);

  int brightnessLeft = analogRead(A4);
  int brightnessRight = analogRead(A5);
  int brightnessTop = analogRead(A3);
  int brightnessBottom = analogRead(A2);

  Serial.println(brightnessLeft);
  Serial.println(brightnessRight);
  Serial.println(brightnessTop);
  Serial.println(brightnessBottom);
  // put your main code here, to run repeatedly:

  //BRIGHTNESS SENSOR MODE
  /*
  if ((brightnessLeft > brightnessRight) && (brightnessLeft < threshold)) {
    myStepper.step(128); //stepper left rotate
  } 
  else if ((brightnessLeft < brightnessRight) && (brightnessRight < threshold)) {
    myStepper.step(-128); //stepper right rotate
  } 
  else {
  }
  */

/*
black  butt digital 2
red  y a1
blue  x a0
white  5v 
green  gnd
*/

  //MANUAL MODE
  int X = analogRead(A0)-512;
  int Y = analogRead(A1)-512;

  //Serial.println(X);
  //Serial.println(Y);
  if (abs(Y) > 100) {
  Stepper_1.step(Y/10);
  }
  if (abs(X) > 100) {
  Stepper_2.step(X/10);
  }

  //Serial.println(buttonPressed);
  //LIGHT MODE

  //IR MODE

}