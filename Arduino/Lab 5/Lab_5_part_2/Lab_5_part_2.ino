#include "Timer.h"

const int B[] = {6, 7, 8, 9, 10}; //LED pins
const int buttonPin = 2; //Joystick button pin

enum STATE {LED_1_ON, LED_2_ON, LED_3_ON, LED_4_ON, LED_5_ON, LED_1_OFF, LED_2_OFF, LED_3_OFF, LED_4_OFF, LED_5_OFF} gState = LED_3_ON;
bool buttonPressed;
int X;
int Y;

void LED_MOVE(void){

////////////////////////////////////////////ON STATES
  switch (gState) {
      case LED_1_ON:
          if (analogRead(A0) > 525) {
            gState = LED_2_ON; }
          else if (analogRead(A0) < 515) {
            gState = LED_1_ON; }
          else {
            gState = LED_1_ON; }
          if(digitalRead(2) == 0) {
            gState = LED_1_OFF;
          }
      break;

      case LED_2_ON:
          if (analogRead(A0) > 525) {
            gState = LED_3_ON; }
          else if (analogRead(A0) < 515) {
            gState = LED_1_ON; }
          else {
            gState = LED_2_ON; }
          if (digitalRead(2) == 0) {
            gState = LED_2_OFF;
          }
      break;

      case LED_3_ON:
          if (analogRead(A0) > 525) {
            gState = LED_4_ON; }
          else if (analogRead(A0) < 515) {
            gState = LED_2_ON; }
          else {
            gState = LED_3_ON; }
          if(digitalRead(2) == 0) {
            gState = LED_3_OFF;
          }
      break;

      case LED_4_ON:
          if (analogRead(A0) > 525) {
            gState = LED_5_ON; }
          else if(analogRead(A0) < 515) {
            gState = LED_3_ON; }
          else {
            gState = LED_4_ON; }
          if(digitalRead(2) == 0) {
            gState = LED_4_OFF;
          }
      break;

      case LED_5_ON:
          if(analogRead(A0) > 525) {
            gState = LED_5_ON; }
          else if(analogRead(A0) < 515) {
            gState = LED_4_ON; }
          else {
            gState = LED_5_ON; }
          if(digitalRead(2) == 0) {
            gState = LED_5_OFF;
          }
      break;

////////////////////////////////////////////OFF STATES

      case LED_1_OFF:
          if (analogRead(A0) > 525) {
            gState = LED_2_OFF; }
          else if (analogRead(A0) < 515) {
            gState = LED_1_OFF; }
          else {
            gState = LED_1_OFF; }
          if(digitalRead(2) == 0) {
            gState = LED_1_ON;
          }
      break;

      case LED_2_OFF:
          if (analogRead(A0) > 525) {
            gState = LED_3_OFF; }
          else if (analogRead(A0) < 515) {
            gState = LED_1_OFF; }
          else {
            gState = LED_2_OFF; }
          if(digitalRead(2) == 0) {
            gState = LED_2_ON;
          }
      break;

      case LED_3_OFF:
          if (analogRead(A0) > 525) {
            gState = LED_4_OFF; }
          else if (analogRead(A0) < 515) {
            gState = LED_2_OFF; }
          else {
            gState = LED_3_OFF; }
          if(digitalRead(2) == 0) {
            gState = LED_3_ON;
          }
      break;

      case LED_4_OFF:
          if (analogRead(A0) > 525) {
            gState = LED_5_OFF; }
          else if(analogRead(A0) < 515) {
            gState = LED_3_OFF; }
          else {
            gState = LED_4_OFF; }
          if(digitalRead(2) == 0) {
            gState = LED_4_ON;
          }
      break;

      case LED_5_OFF:
          if(analogRead(A0) > 525) {
            gState = LED_5_OFF; }
          else if(analogRead(A0) < 515) {
            gState = LED_4_OFF; }
          else {
            gState = LED_5_OFF; }
          if(digitalRead(2) == 0) {
            gState = LED_5_ON;
          }
      break;
  }
//////////////////////////////////////////////ON ACTIONS
    switch(gState) {
      case LED_1_ON:
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
      break;

      case LED_2_ON:
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
      break;

      case LED_3_ON:
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
      break;

      case LED_4_ON:
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
      break;

      case LED_5_ON:
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
      break;

//////////////////////////////////////////////OFF ACTIONS (FOR KEEPING TRACK OF LED)

      case LED_1_OFF:
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
      break;

      case LED_2_OFF:
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
      break;

      case LED_3_OFF:
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
      break;

      case LED_4_OFF:
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
      break;

      case LED_5_OFF:
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
      break;
  }
}

void setup() {
  // put your setup code here, to run once:
  TimerSet(500); //this value (250) is the period in ms
  TimerOn();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  digitalWrite(B[2], HIGH);
  int X = analogRead(A0);
  int Y = analogRead(A1);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool buttonPressed = digitalRead(2);
  int X = analogRead(A0);
  int Y = analogRead(A1);
  LED_MOVE();
  while(!TimerFlag){}
  TimerFlag = 0;  
  //Serial.println(analogRead(A0));
  //Serial.println(analogRead(A1));
  //Serial.println(buttonPressed);
}
