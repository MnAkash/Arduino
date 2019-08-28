float kp,kd;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() 
{
if(Serial.available()>0)
  {
     kd = Serial.read();
  }
if(Serial.available()>0)
  {
    kp = Serial.read();
  }
}
