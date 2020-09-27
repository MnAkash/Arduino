#include<Servo.h> 
 Servo servo;
 int i;
 void setup() 
{
 servo.attach(6);
 
}

void loop() {

  servo.write(90);
  delay(500);
  
}




/*
 * void loop() {
 
  for(i=0;i<180;i++)
  {
    servo.write(i);
    delay(5);
  }
  delay(2000);

  for(i=179;i>0;i--)
  {
    servo.write(i);
    delay(5);
  }
  delay(2000);
}
*/
