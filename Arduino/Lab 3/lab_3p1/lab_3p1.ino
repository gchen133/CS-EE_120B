//Lab 3 Part 1
// C++ code
//

enum STATE {INIT, NEXT_STATE} gState = INIT;
const int ledPin = 2;
const int buttonPin = 13;

int buttonPressed = 0;
int prevButtState = LOW;
int ledState = LOW;

void tick(void) {
  
  // transitions
  switch (gState) {
    case INIT:
    gState = NEXT_STATE;
    break;
    
    case NEXT_STATE:
    gState = NEXT_STATE;
    break;
  }
  
  // actions
  switch (gState) {
    case INIT:
    break;

    case NEXT_STATE:
    digitalWrite(2, LOW);
  }
}

void setup() {
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  buttonPressed = digitalRead(buttonPin);

  if (buttonPressed != prevButtState &&  buttonPressed == HIGH) {
    ledState = (ledState == LOW ? HIGH : LOW);
    digitalWrite(ledPin, ledState);
  }
  prevButtState = buttonPressed;

  //tick(); NOT NECESSARY FOR PART 1
}