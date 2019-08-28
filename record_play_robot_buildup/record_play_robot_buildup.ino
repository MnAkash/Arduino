#include <Servo.h>  
  Servo servo_1;
  int AnalogOut = 0;
  int NewAnalogOut = 0;
  int pin_Button = 12;
  int pin_Button_State = 0;
  int pin_Button_State_Last = 0;
  int storage[500];
  int storage_loc = 0;
  int recording = 0;
  int last_storage_loc;
  void setup() 
  {
    Serial.begin(9600);
    servo_1.attach(11);
    pinMode(pin_Button, INPUT);
  }
  
  void loop() {
  if (recording == 0)
  {
      int sensorValue = analogRead(A0);
      NewAnalogOut = map(sensorValue, 0, 1023, 0, 180);
      if (abs(NewAnalogOut - AnalogOut) > 2)
      {
        servo_1.write(AnalogOut);
        AnalogOut = NewAnalogOut;
      }
  }
  delay(1);
  if ( recording == 1)
  {     
      if (storage_loc < 500) 
      {
        int sensorValue = analogRead(A0);
         NewAnalogOut = map(sensorValue, 0, 1023, 0, 180);
         servo_1.write(NewAnalogOut);
        storage[storage_loc] = NewAnalogOut;
        delay(100);
        Serial.println(storage[storage_loc]);
        storage_loc++;
        last_storage_loc=storage_loc; 
      }
  } 
  else if (recording > 1) 
  {
      storage_loc = 0;
      while (true) 
      {  
          if (storage_loc <= last_storage_loc)
          {
            servo_1.write(storage[storage_loc]);
            storage_loc++;
            delay(100);
          }
          else if(storage_loc > last_storage_loc)
          {
            storage_loc=0;
          }
      } 
  }
  pin_Button_State = digitalRead(pin_Button);
  if (pin_Button_State != pin_Button_State_Last) 
  {
      if (pin_Button_State == HIGH) {
      recording++;
      Serial.println(recording);     
      } else 
      {}
      delay(50);
  }
  pin_Button_State_Last = pin_Button_State;
  }
