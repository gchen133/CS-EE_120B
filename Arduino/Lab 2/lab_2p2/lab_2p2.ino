// C++ code
//
const int B[] = {2, 3, 4, 5};
int a = 0x00;
int A = 0x00;
unsigned int a0, a1, a2, a3;

void setup()
{
  pinMode(B[0], OUTPUT);
  pinMode(B[1], OUTPUT);
  pinMode(B[2], OUTPUT);
  pinMode(B[3], OUTPUT);
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

      digitalWrite(B[0], LOW);
      digitalWrite(B[1], LOW);
      digitalWrite(B[2], LOW);
      digitalWrite(B[3], LOW);

      A = (5.0/9.0) * (a - 32.0);
      writeToB(A);
    }
  }
}