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

int Step=0;


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
   /* motor[0].write(storage[0][0]);
    motor[1].write(storage[1][0]);
    motor[2].write(storage[2][0]);
    motor[3].write(storage[3][0]);
    delay(1000);*/
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
 // Serial.println(task);
 }
    
    
  
 }


void record_run()
{  

      while(true)
    {
      int s0=storage[0][Start_point];
      int e0=storage[0][Next_point];
      int s1=storage[1][Start_point];
      int e1=storage[1][Next_point];
      int s2=storage[2][Start_point];
      int e2=storage[2][Next_point];
      int s3=storage[3][Start_point];
      int e3=storage[3][Next_point];
      
        /*int a=abs(storage[0][Start_point]-storage[0][Next_point]);
  int b=abs(storage[1][Start_point]-storage[1][Next_point]);
  int c=abs(storage[2][Start_point]-storage[2][Next_point]);
  int d=abs(storage[3][Start_point]-storage[3][Next_point]);*/
  int a[4]={abs(s0-e0),abs(s1-e1),abs(s2-e2),abs(s3-e3)};
  
  int highest=a[0];
  for(int j=0;j<=3;j++)
  {
    if(a[j]>highest) highest=a[j];   
  }
  
  while(true)
  {
    /*if(s0<=e0)       
    {
      motor[0].write(s0);
      s0=s0+(round(a/20)+1);                                //increasing order onujay protteker increment nirdharon hobe
    }

    if(s1<=e1)       
    {
      motor[1].write(s1);
      s1=s1+(round(b/20)+1);                                //increasing order onujay protteker increment nirdharon hobe
    }
    if(s2<=e2)       
    {
      motor[2].write(s2);
      s2=s2+(round(c/20)+1);                                //increasing order onujay protteker increment nirdharon hobe
    }
    if(s3<=e3)       
    {
      motor[3].write(s3);
      s3=s3+(round(d/20)+1);                                //increasing order onujay protteker increment nirdharon hobe
    }*/

   motor[0].write(map(Step,0,50,s0,e0));      //18 june 2018 dupure khabar somoy ei algo mathay ashche ;)
   motor[1].write(map(Step,0,50,s1,e1));
   motor[2].write(map(Step,0,50,s2,e2));       //50 step e kaj kortese
   motor[3].write(map(Step,0,50,s3,e3));
            
   if(Step==50)
   {
    break;
   }
   Step++;
   delay(map(highest,0,180,0,50));              //700/50=14(delay must be above14 so 50 dewa hoise...karon 0 to 180 approx 700ms lage
   Serial.println(map(highest,0,180,0,50));
  }
      delay(50);
      Step=0;
      Start_point++;
      Next_point++;
      if(Start_point==last_storage_loc+1)
      {
        Start_point=0;
        //Next_point=1;
        /*motor[0].write(storage[0][0]);
        motor[1].write(storage[1][0]);
        motor[2].write(storage[2][0]);
        motor[3].write(storage[3][0]);
        delay(500);*/
       /* for(int x=0;x<=50;x++)
        {
          motor[0].write(map(x,0,50,storage[0][last_storage_loc],storage[0][0]));
          motor[1].write(map(x,0,50,storage[1][last_storage_loc],storage[1][0]));
          motor[2].write(map(x,0,50,storage[2][last_storage_loc],storage[2][0]));
          motor[3].write(map(x,0,50,storage[3][last_storage_loc],storage[3][0]));
          delay(50);
        }*/
      }
      if(Next_point==last_storage_loc+1)
        {
          Next_point=0;
        }
      /*if(checkButton()==4)
        {
          resetFunc();
        }*/
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

int highest(int a,int b,int c,int d)
{
  int z[4]={a,b,c,d};
  int highest=a;
  for(int j=0;j<=3;j++)
  {
    if(z[j]>highest) highest=z[j]; 
  }
}

