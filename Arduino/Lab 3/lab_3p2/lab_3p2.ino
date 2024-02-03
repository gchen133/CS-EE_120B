//Lab 3 Part 1
// C++ code
//

enum COLOR_STATE {RED_STATE, GREEN_STATE, YELLOW_STATE} gState = RED_STATE;
char buttonPressed = 0;

void tick(void) {
  
  // transitions
  switch (gState) {
    case RED_STATE:
      if (buttonPressed == 1) {
        gState = GREEN_STATE;
      }
      else {
        gState = RED_STATE;
      }
      break;
    
    case GREEN_STATE:
      if (buttonPressed == 1) {
        gState = YELLOW_STATE;
      }
      else {
        gState = GREEN_STATE;
      }
      break;

    case YELLOW_STATE:
      if (buttonPressed == 1) {
        gState = RED_STATE;
      }
      else {
        gState = YELLOW_STATE;
      }
      break;
  }
  
  // actions
  switch (gState) {
    case RED_STATE:
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    break;

    case GREEN_STATE:
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    break;

    case YELLOW_STATE:
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    break;

  }
}

void setup() {
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop()
{
  buttonPressed = digitalRead(13);
  tick();
  delay(100);
}