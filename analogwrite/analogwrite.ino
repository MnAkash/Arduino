void setup() {
pinMode(9,OUTPUT);
pinMode(A1,INPUT);
Serial.begin(9600);
}

void loop() {
  analogWrite(9,255);
  
  Serial.println(analogRead(A1));
  delay(400);

}
