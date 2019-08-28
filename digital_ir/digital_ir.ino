int ir;
void setup() {
  // put your setup code here, to run once
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ir=digitalRead(2);
Serial.print("ir:");
Serial.println(ir);
delay(100);
}
