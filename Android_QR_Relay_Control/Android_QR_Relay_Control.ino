String readString;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }
  if (readString.length() >0) {
    Serial.println(readString);
    readString="";
/*    if (readString == "A")  //second generated string from android
    {
      digitalWrite(relay, HIGH);
      delay(3000);                  //Wait 3 sec
      digitalWrite(relay, LOW);
    readString="";
  } */
 }
}
