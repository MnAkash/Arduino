int ledPin = 13; 
int state = 0;

void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(12, OUTPUT);
 digitalWrite(12, HIGH);
 digitalWrite(ledPin, LOW);
 
 Serial.begin(38400); // Default connection rate for my BT module
}
 
void loop() {

 
 if(Serial.available() > 0){
 {
 state = Serial.read();
 }

 if (state == '0') {
 digitalWrite(ledPin, LOW);
 
 }

 else if (state == '1')
 {
 digitalWrite(ledPin, HIGH);
 
 }
}
}
