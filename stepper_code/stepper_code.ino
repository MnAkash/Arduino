/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers
const int stepPin = 5; 
const int dirPin = 2; 
int Step_delay=600;
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 250; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(Step_delay); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(Step_delay); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x <250; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(Step_delay);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(Step_delay);
  }
  delay(1000);
}
