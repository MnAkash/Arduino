void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int i;i<11;i++)
  {
    int a=map(i, 0, 10, 185,   0);
    Serial.println(a);
    delay(1000);
  }
  
}
