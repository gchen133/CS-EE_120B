// C++ code
//
const int B[] = {2, 3, 4, 5};
int a = 0x00;
int a0, a1, a2, a3;

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
      resetB();
      int val = analogRead(A0);
      if (val < 200){
        digitalWrite(B[3],LOW);
        digitalWrite(B[2],LOW);
        digitalWrite(B[1],LOW);
        digitalWrite(B[0],LOW);
      }
      else if (val < 400){
        digitalWrite(B[3],LOW);
        digitalWrite(B[2],LOW);
        digitalWrite(B[1],LOW);
        digitalWrite(B[0],HIGH);
      }
      else if (val < 600){
        digitalWrite(B[3],LOW);
        digitalWrite(B[2],LOW);
        digitalWrite(B[1],HIGH);
        digitalWrite(B[0],HIGH);
      }
      else if (val < 800){
        digitalWrite(B[3],LOW);
        digitalWrite(B[2],HIGH);
        digitalWrite(B[1],HIGH);
        digitalWrite(B[0],HIGH);
      }
      else {
        digitalWrite(B[3],HIGH);
        digitalWrite(B[2],HIGH);
        digitalWrite(B[1],HIGH);
        digitalWrite(B[0],HIGH);
      }
  }
}