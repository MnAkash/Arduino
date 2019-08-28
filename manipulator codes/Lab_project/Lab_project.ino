
#define resetPin 4
#include <Servo.h>
Servo motor[6];
int motor_position[6]={90,40,43,135,180,139};


int motor_position_red[9][6]={90,40,43,135,83,139,49,40,43,135,83,139,52,49,31,110,83,139,52,49,31,167,83,139,52,49,31,167,83,81,52,49,31,110,83,81,145,56,31,110,83,81,145,56,27,160,83,81,145,56,27,160,83,137};
int motor_position_black[9][6]={90,40,43,135,83,139,49,40,43,135,83,139,52,49,31,110,83,139,52,49,31,167,83,139,52,49,31,167,83,81,52,49,31,110,83,81,170,56,31,110,83,81,170,56,27,160,83,81,170,56,27,160,83,137};
int motor_position_green[9][6]={90,40,43,135,83,139,49,40,43,135,83,139,52,49,31,110,83,139,52,49,31,167,83,139,52,49,31,167,83,81,52,49,31,110,83,81,130,56,31,110,83,81,130,56,27,160,83,81,130,56,27,160,83,137};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
String readString;                                                    
int storage[6][50];
int storage_loc= 0;
int last_storage_loc=0;
int Start_point=0;
int Next_point=1;
int i=0;
int Speed=75;
int _delay=50; //dont edit it
int Delay=map(Speed,1,100,100,(700/_delay));   //delay must be above 700ms/50step=14 karon 0 to 180 degree approx 700ms lage

int Step=0;
int temp;

int pin2=0;
int pin7=0;
int pin8=0;

void setup()
{
  digitalWrite(resetPin,HIGH);
  pinMode(resetPin,OUTPUT);
  /*digitalWrite(2,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  
  pinMode(2,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  */
  Serial.begin(9600);
  motor[0].attach(11);
  motor[1].attach(10);
  motor[2].attach(9);
  motor[3].attach(6);
  motor[4].attach(5);
  motor[5].attach(3);


  
  
  motor[0].write(motor_position[0]);
  motor[1].write(motor_position[1]);
  motor[2].write(motor_position[2]);
  motor[3].write(motor_position[3]);
  motor[4].write(motor_position[4]);
  motor[5].write(motor_position[5]);

  delay(2000);

  
}
void loop()
{
    while (Serial.available())
     {
        delay(3);  
        char c = Serial.read();
        readString += c; 
     }
    /*pin2=digitalRead(2);
    pin7=digitalRead(7);
    pin8=digitalRead(8);

    int result=pin2+pin7*2+pin8*4;

   //Serial.println(result);
    Serial.print(pin8);
    Serial.print(pin7);
    Serial.println(pin2);
    Serial.println(" ");
    //delay(500);
    */  
      if (readString.length() >0)
      {  
        if (readString == "red")
           {
              Serial.println(readString);
              readString="";
              while(storage_loc<9)
              {
                for(i=0;i<=5;i++)
                  {
                    storage[i][storage_loc] = motor_position_red[storage_loc][i];
                    
                  }
                    last_storage_loc=storage_loc;
                    storage_loc++;
              }
              record_run();
              
              while(Serial.available()>0)
            {
              Serial.read();
            }
            }
          
        if (readString == "black")
           {
              Serial.println(readString);
              readString="";
              while(storage_loc<9)
              {
                for(i=0;i<=5;i++)
                  {
                    storage[i][storage_loc] = motor_position_black[storage_loc][i];
                    
                  }
                    last_storage_loc=storage_loc;
                    storage_loc++;
              }
              record_run();
              
              while(Serial.available()>0)
            {
              Serial.read();
            }
            }
           
        if (readString == "green")
           {
              Serial.println(readString);
              readString="";
              while(storage_loc<9)
              {
                for(i=0;i<=5;i++)
                  {
                    storage[i][storage_loc] = motor_position_green[storage_loc][i];
                    
                  }
                    last_storage_loc=storage_loc;
                    storage_loc++;
              }
              record_run();
              while(Serial.available()>0)
            {
              Serial.read();
            }
            }
        
      }
      else
      {
        motor[0].write(motor_position[0]);
        motor[1].write(motor_position[1]);
        motor[2].write(motor_position[2]);
        motor[3].write(motor_position[3]);
        motor[4].write(motor_position[4]);
        motor[5].write(motor_position[5]);
      }

           /* while(Serial.available())
            {
              Serial.read();
            }
            Serial.println(Serial.read());*/
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
      int s4=storage[4][Start_point];
      int e4=storage[4][Next_point];
      int s5=storage[5][Start_point];
      int e5=storage[5][Next_point];
      int a[6]={abs(s0-e0),abs(s1-e1),abs(s2-e2),abs(s3-e3),abs(s4-e4),abs(s5-e5)};
      
      int highest=a[0];
      for(int j=0;j<=5;j++)
      {
        if(a[j]>highest) highest=a[j];   
      }
      
      while(true)
      {
    
           motor[0].write(map(Step,0,50,s0,e0));      //18 june 2018 dupure khabar somoy ei algo mathay ashche -_-
           motor[1].write(map(Step,0,50,s1,e1));
           motor[2].write(map(Step,0,50,s2,e2));       //50 step e kaj kortese
           motor[3].write(map(Step,0,50,s3,e3));
           motor[4].write(map(Step,0,50,s4,e4));
           motor[5].write(map(Step,0,50,s5,e5));
                    
           if(Step==50)
           {
            break;
           }
           Step++;
           delay(map(highest,0,180,0,Delay));              //700/50step=14(delay must be above14 so 50 dewa hoise...karon 0 to 180 approx 700ms lage
           //Serial.println(map(highest,0,180,0,Delay));
      }
      delay(Delay);
      Step=0;
      Start_point++;
      Next_point++;

     if(Next_point==last_storage_loc+1)
      {
        Next_point=0;
      }
         
     if(Start_point==last_storage_loc+1)
      {
        storage_loc= 0;
        last_storage_loc=0;
        Start_point=0;
        Next_point=1;
        break;
      }
      
    }
}


//copyright @ akash
