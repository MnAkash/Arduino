const int f_ir=33;
const int b_ir=30;
const int l_ir=31;
const int r_ir=32;

void setup() {
  // put your setup code here, to run once:
  pinMode(f_ir, INPUT);
  pinMode(b_ir, INPUT);
  pinMode(l_ir, INPUT);
  pinMode(r_ir, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("FRONT: ");
Serial.println(digitalRead(f_ir));

Serial.print("BACK: ");
Serial.println(digitalRead(b_ir));

Serial.print("LEFT: ");
Serial.println(digitalRead(l_ir));

Serial.print("RIGHT: ");
Serial.println(digitalRead(r_ir));

delay(1000);
}
