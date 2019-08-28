#define buttonPin 12
#include <Servo.h>  
Servo motor[4];
                                                       
int AnalogOut[4]={0,0,0,0};
int NewAnalogOut[4]= {0,0,0,0};
int storage[4][50];
int storage_loc= 0;
int recording = 0;
int last_storage_loc=0;
int Start_point=0;
int Next_point=1;
int i=0;


      /*int s0=storage[0][Start_point];
      int e0=storage[0][Next_point];
      int s1=storage[1][Start_point];
      int e1=storage[1][Next_point];
      int s2=storage[2][Start_point];
      int e2=storage[2][Next_point];
      int s3=storage[3][Start_point];
      int e3=storage[3][Next_point];*/


  int Switch = 12;
  int Switch_State = 0;
  int Switch_State_Last = 0;
  int counter = 0;
  int task=0;

/*int debounce = 20;          
int DCgap = 250;            
int holdTime = 1000;        
int longHoldTime = 3000;    
boolean buttonVal = HIGH;   
boolean buttonLast = HIGH;  
boolean DCwaiting = false;  
boolean DConUp = false;     
boolean singleOK = true;    
long downTime = -1;        
long upTime = -1;          
boolean ignoreUp = false; 
boolean waitForUp = false;       
boolean holdEventPast = false;  
boolean longHoldEventPast = false;*/

void(* resetFunc) (void) = 0;


void setup()
{
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
  motor[0].attach(11);
  motor[1].attach(10);
  motor[2].attach(9);
  motor[3].attach(6);
  pinMode(Switch, INPUT);
}
void loop()
{
  servorun();
  //int flag=checkButton();
  
  if(task==1)      //button short press
   {
    for(i=0;i<=3;i++)
      {
        storage[i][storage_loc] = NewAnalogOut[i];
        //Serial.println(storage[i][storage_loc]);
        Serial.println(storage_loc);
        
      }
        last_storage_loc=storage_loc;
        storage_loc++;
        task=0;
  }
  else if(task==2)      //button long press
  {
    record_run();        
  }

Switch_State = digitalRead(Switch);
  if (Switch_State == HIGH) {
  counter++;
  if(counter>50 && counter<59)
  {
    task=2;    //switch hold and release
    counter=0;
  }    
  
  } 
  else if(Switch_State == LOW && (Switch_State != Switch_State_Last) && counter<50 && counter>2)
  {
    task=1;     //single click
    counter=0;
  }
  delay(15);
  
  Switch_State_Last = Switch_State;  
  
 if(task==1 || task==2)
 {
  //Serial.println(task);
 }
    
    
  
 }


void record_run()
{
     storage_loc = 0;
    while (true) 
     {
        
     
      if (storage_loc <= last_storage_loc) 
        {
          for(i=0;i<=3;i++)
          {
            motor[i].write(storage[i][storage_loc]);
            
            //Serial.println(storage[i][storage_loc]);
            Serial.println(storage_loc);
          }
          storage_loc++;
            delay(600);

        }
      else if(storage_loc > last_storage_loc)
      {
        storage_loc=0;
      }
            
      
         
    }

}
void servorun()
{
  int i=0;      
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


/*int checkButton() {    
   int event = 0;
   buttonVal = digitalRead(buttonPin);
   // Button pressed down
   if (buttonVal == LOW && buttonLast == HIGH && (millis() - upTime) > debounce)
   {
       downTime = millis();
       ignoreUp = false;
       waitForUp = false;
       singleOK = true;
       holdEventPast = false;
       longHoldEventPast = false;
       if ((millis()-upTime) < DCgap && DConUp == false && DCwaiting == true)  DConUp = true;
       else  DConUp = false;
       DCwaiting = false;
   }
   // Button released
   else if (buttonVal == HIGH && buttonLast == LOW && (millis() - downTime) > debounce)
   {        
       if (not ignoreUp)
       {
           upTime = millis();
           if (DConUp == false) DCwaiting = true;
           else
           {
               event = 2;
               DConUp = false;
               DCwaiting = false;
               singleOK = false;
           }
       }
   }
   // Test for normal click event: DCgap expired
   if ( buttonVal == HIGH && (millis()-upTime) >= DCgap && DCwaiting == true && DConUp == false && singleOK == true && event != 2)
   {
       event = 1;
       DCwaiting = false;
   }
   // Test for hold
   if (buttonVal == LOW && (millis() - downTime) >= holdTime) {
       // Trigger "normal" hold
       if (not holdEventPast)
       {
           event = 3;
           waitForUp = true;
           ignoreUp = true;
           DConUp = false;
           DCwaiting = false;
           //downTime = millis();
           holdEventPast = true;
       }
       // Trigger "long" hold
       if ((millis() - downTime) >= longHoldTime)
       {
           if (not longHoldEventPast)
           {
               event = 4;
               longHoldEventPast = true;
           }
       }
   }
   buttonLast = buttonVal;
   return event;
}*/


