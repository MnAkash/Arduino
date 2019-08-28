void setup() {
  // put your setup code here, to run once:
  digitalWrite(4,HIGH);
pinMode(10,OUTPUT);
pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int i;
for(i=0;i<=255;i++)
{
analogWrite(10,i);
delay(40);
}
delay(1000);
digitalWrite(4,LOW);
delay(100);
}
