#include<Servo.h>
Servo motor[2];
int pos[2][4]={0,90,45,180,0,45,90,180};
int i=0;

void setup() {
  motor[0].attach(9);
  
  motor[1].attach(10);
  Serial.begin(9600);

}

void loop() {
 /* for(i=0;i<=4;i++)
  {
    motor[0].write(pos[0][i]);
    motor[1].write(pos[1][i]);
    delay(700);
    if(i==4)
    {
      i=0;
    }
  }*/
  
  
  int a=motor[0].read();
  Serial.println(a);
  delay(1000);
  
  }
