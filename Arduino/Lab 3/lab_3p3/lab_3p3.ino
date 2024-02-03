//Lab 3 Part 1
// C++ code
//

enum STATE {START, X_DIGIT, Y_DIGIT, Y_BOUNCE, UNLOCK} goState = START;
char xPressed = 0;
char yPressed = 0;
char zPressed = 0;
bool ledState = LOW;


void tick(void) {
  
  // transitions
  switch (goState) {

      case START:
        if (xPressed == 1) {
          goState = X_DIGIT; }
      break;

      case X_DIGIT:
        if (yPressed == 1) {
          goState = Y_DIGIT; }
      break;
      
      case Y_DIGIT:
        if (yPressed == 0) {
          goState = Y_BOUNCE; }
      break;

      case Y_BOUNCE: //
        if (zPressed == 1) {
          goState = UNLOCK; }
        else if (xPressed == 1) {
          goState = START; }
        else if (yPressed == 1) {
          goState = START; }
      break;

      case UNLOCK:
        goState = START;
      break;
  }
  
  // actions
  switch (goState) {
      case START:
      break;

      case X_DIGIT:
      Serial.println("X DIGIT ACCEPTED");
      break;

      case Y_DIGIT:
      Serial.println("Y DIGIT ACCEPTED"); 
      break;

      case Y_BOUNCE:
      break;

      case UNLOCK:
      Serial.println("PASSWORD ACCEPTED");
      ledState = digitalRead(2);

        if (ledState == LOW) {
          digitalWrite(2, HIGH); }
        else {
          digitalWrite(2, LOW); }
      break;
  }
}

void setup() {
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  xPressed = digitalRead(13);
  yPressed = digitalRead(12);
  zPressed = digitalRead(11);

  tick();
}