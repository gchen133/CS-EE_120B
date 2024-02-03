// C++ code
//
const int B[] = {2, 3, 4, 5};
int a = 0x00;
int a0, a1, a2, a3;

void setup()
{
  pinMode(B[0], HIGH);
  pinMode(B[1], HIGH);
  pinMode(B[2], HIGH);
  pinMode(B[3], HIGH);
  Serial.begin(9600);
}

void resetB()
{
  digitalWrite(B[3],LOW);
  digitalWrite(B[2],LOW);
  digitalWrite(B[1],LOW);
  digitalWrite(B[0],LOW);
}

void writeToB(unsigned char temp)
{
 
  if ((temp>>3) & 0x01){digitalWrite(B[3],HIGH);}
  if ((temp>>2) & 0x01){digitalWrite(B[2],HIGH);}
  if ((temp>>1) & 0x01){digitalWrite(B[1],HIGH);}
  if (temp & 0x01){digitalWrite(B[0],HIGH);}
}


void loop()
{
  while(Serial.available() == 0) {
    // Wait for input
  a = Serial.parseInt();
    if (Serial.read() == '\n') {

      // Turn off all LEDs
      digitalWrite(B[0], LOW);
      digitalWrite(B[1], LOW);
      digitalWrite(B[2], LOW);

      // Update LED state based on the value of a
      if (a < 65) {
        digitalWrite(B[0], HIGH);
      }
      else if (a < 95) {
        digitalWrite(B[1], HIGH);
      } 
      else {
        digitalWrite(B[2], HIGH);
      }
  }
  }
}
  //writeToB(a); //This will display the value of a in binary on the LEDs