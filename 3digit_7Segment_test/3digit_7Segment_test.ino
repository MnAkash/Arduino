/*================= By Akash 29-sep-2020========*/
//Designed for Arduino mega
// Pins to control each digit
const int DIGIT_ONE = 10;//LSB
const int DIGIT_TWO = 11;
const int DIGIT_THREE = 12;//MSB

// Array to store digits
const int digitNo[] = { DIGIT_THREE, DIGIT_TWO, DIGIT_ONE};

//each segments [a,b,c,d,e,f,g]==[pin30 to pin36]

// {a,b,c,d,e,f,g}
int a,p[10][7]={{1,1,1,1,1,1,0}, //0
                 {0,1,1,0,0,0,0}, //1
                 {1,1,0,1,1,0,1}, //2
                 {1,1,1,1,0,0,1}, //3
                 {0,1,1,0,0,1,1}, //4
                 {1,0,1,1,0,1,1}, //5
                 {1,0,1,1,1,1,1}, //6
                 {1,1,1,0,0,0,0}, //7
                 {1,1,1,1,1,1,1}, //8
                 {1,1,1,1,0,1,1}}; //9

void setup() 
{
  //[a,b,c,d,e,f,g]==[30 to 36]
  for(int i=30;i<=36;i++) //pin 30 to 36 for each segment control
  {
    pinMode(i,OUTPUT);
  }
  pinMode(DIGIT_ONE,OUTPUT);//LSB
  pinMode(DIGIT_TWO,OUTPUT);
  pinMode(DIGIT_THREE,OUTPUT);//MSB
  
  //Turning digits OFF
  digitalWrite(DIGIT_ONE, HIGH);//LSB
  digitalWrite(DIGIT_TWO, HIGH);
  digitalWrite(DIGIT_THREE, HIGH);//MSB
}

void loop() 
{
  digit3(346);
}


void digit(int n)
{
  for(a=30;a<=36;a++)   //30-36 digital pin use korsi
  {
    digitalWrite(a,p[n][a-30]);             
  }
}
void digit3(int n)  // displays 3 numbers simultaneously
{
  int x = n/100;
  int y = (n%100)/10;
  int z = (n%100)%10;
  digitalWrite(digitNo[1], HIGH);
  digitalWrite(digitNo[2], HIGH);
  digitalWrite(digitNo[0], LOW);//Turning DIGIT 3 ON
  digit(x);
  delay(5);
  digitalWrite(digitNo[0], HIGH);
  digitalWrite(digitNo[2], HIGH);
  digitalWrite(digitNo[1], LOW);//Turning DIGIT 3 ON
  digit(y);
  delay(5);
  digitalWrite(digitNo[0], HIGH);
  digitalWrite(digitNo[1], HIGH);
  digitalWrite(digitNo[2], LOW);//Turning DIGIT 3 ON
  digit(z);
  delay(5);
}
