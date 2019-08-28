//left motor red wire out4 black wire out 3
//right motor red out 2 black out 1
//in1= 6, in2= 5, in3= 4, in4= 3
//ir gives 1 on black, and 0 on white

int maxpower= 200;
int minDis= 60;

//motorPins
const int motorPin1 = 6;
const int motorPin2 = 5;
const int motorPin3 = 3;
const int motorPin4 = 4;

const int fSonarTrig = 29;
const int fSonarEcho = 28;
const int bSonarTrig = 40;
const int bSonarEcho = 41;

const int f_ir=33;
const int b_ir=30;
const int l_ir=31;
const int r_ir=32;

int fDistance;
int bDistance;



void setup() {
  // put your setup code here, to run once:
 //initializing motorPins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
 pinMode(fSonarTrig, OUTPUT);
  pinMode(fSonarEcho, INPUT);
   
 pinMode(bSonarTrig, OUTPUT);
  pinMode(bSonarEcho, INPUT);

  pinMode(f_ir, INPUT);
  pinMode(b_ir, INPUT);
  pinMode(l_ir, INPUT);
  pinMode(r_ir, INPUT);
  
  
  Serial.begin(9600);
   delay(3000);
}

void loop() {
 // put your main code here, to run repeatedly:

/*
//ir functions
while (digitalRead(f_ir)==0 ||  digitalRead(b_ir)==0 || digitalRead(l_ir)==0 || digitalRead(r_ir)==0){
while(digitalRead(f_ir)==0){
  goBackward();
} while(digitalRead(b_ir)==0){
goForward();
}while(digitalRead(l_ir)==0){
goRight();
}while(digitalRead(r_ir)==0){
goLeft();
}
}
*/





while (digitalRead(f_ir)==1 &&  digitalRead(b_ir)==1 && digitalRead(l_ir)==1 && digitalRead(r_ir)==1){

//sonar functions 
fDistance=trigger(fSonarTrig,fSonarEcho);
bDistance=trigger(bSonarTrig,bSonarEcho);
  Serial.print("Front: ");
Serial.println(fDistance);
Serial.print("Back: ");
Serial.println(bDistance);


if(fDistance <minDis && fDistance>1){
  fAttack();
  delay(200);

 
} else if(bDistance <minDis && bDistance>1){
 bAttack();
 delay(200);

 
}else {
rotate();
delay(200);

}
}










}














//motor functions

void goForward()
{
  analogWrite(motorPin1, 100);
  analogWrite(motorPin2 , 0);
  analogWrite(motorPin3, 100);
  analogWrite(motorPin4, 0);
 
}

void goBackward()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2 , 100);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 100);
  
}

void goLeft()
{
  analogWrite(motorPin1, 150);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 50);
  
}

void goRight()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 50);
  analogWrite(motorPin3, 150);
  analogWrite(motorPin4, 0);
  
}

void brake()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);

}


void rotate()
{
  analogWrite(motorPin1, 100);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 100);
  
}

void fAttack()
{
  analogWrite(motorPin1, maxpower);
  analogWrite(motorPin2 , 0);
  analogWrite(motorPin3, maxpower);
  analogWrite(motorPin4, 0);
 
}
void bAttack()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2 , maxpower);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, maxpower);
 
}

//sonar functions
long mstocm(long microseconds)
{
 
  return (microseconds*346.3)/2/10000;
}

int trigger(int trigPin,int echopin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int distance =  mstocm(pulseIn(echopin, HIGH));
  return distance;
}
