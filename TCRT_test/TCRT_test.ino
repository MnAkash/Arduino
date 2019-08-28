void setup() {
  
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
pinMode(A6,INPUT);
pinMode(A7,INPUT);
Serial.begin(9600);
}

void loop() {
  
 for(int i= 0;i< 4;i++)
 {
  int a=analogRead(i);
  Serial.print(a); 
  Serial.print(" ");
 }
 Serial.println();
  delay(400);


}
