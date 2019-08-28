 #include <Servo.h>  
  Servo motor[4];                                      //15 second cholbe for storage 150
                                                         
 
  int AnalogOut[4]={0,0,0,0};
  int NewAnalogOut[4]= {0,0,0,0};
  int Switch = 12;
  int Switch_State = 0;
  int Switch_State_Last = 0;
  int storage[4][150];
  int storage_loc= 0;
  int recording = 0;
  int last_storage_loc=0;
  void setup() 
  {
  Serial.begin(9600);
  motor[0].attach(11);
  motor[1].attach(10);
  motor[2].attach(9);
  motor[3].attach(6);
  pinMode(Switch, INPUT);
  }
  
  void loop() {
    int i;
  if (recording == 0) 
  {    
    int sensorValue[4] = {analogRead(A0),analogRead(A1),analogRead(A2),analogRead(A3)};   
    for(i=0;i<=3;i++)
      {
        NewAnalogOut[i] = map(sensorValue[i], 0, 1023, 0, 180);
        if (abs(NewAnalogOut[i] - AnalogOut[i]) > 2) 
        {
          motor[i].write(AnalogOut[i]);
          AnalogOut[i] = NewAnalogOut[i];
        }
      }
  }
  delay(1);
  if ( recording == 1) 
  {
    recording = 1;
    for(i=0;i<=3;i++)
    
      if (storage_loc < 150) 
      {
        for(i=0;i<=3;i++)
        {
          int sensorValue[4] = {analogRead(A0),analogRead(A1),analogRead(A2),analogRead(A3)};
          NewAnalogOut[i] = map(sensorValue[i], 0, 1023, 0, 180);
          motor[i].write(NewAnalogOut[i]);
          storage[i][storage_loc] = NewAnalogOut[i];
          delay(100);
          Serial.println(storage[i][storage_loc]);
          storage_loc++;
          last_storage_loc=storage_loc;
        }  
      }
    
  }
  else if (recording > 1) 
  {
  
   storage_loc = 0;
    while (true) 
     {
        
     
      if (storage_loc <= last_storage_loc) 
        {
          for(i=0;i<=3;i++)
          {
            motor[i].write(storage[i][storage_loc]);
            storage_loc++;
            delay(100);
          }
        }
      else if(storage_loc > last_storage_loc)
      {
        storage_loc=0;
      }
         
    }
  }
  
  Switch_State = digitalRead(Switch);
  if (Switch_State != Switch_State_Last) {
  if (Switch_State == HIGH) {
  recording++;
  Serial.println(recording);
  } 
  else 
  {
  }
  delay(50);
  }
  Switch_State_Last = Switch_State;
  }

