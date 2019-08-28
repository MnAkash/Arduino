int incomingByte = 0;   // for incoming serial data
int incomingByte1=0;
unsigned int lowerBit = 0;
unsigned int higherBit = 0;
unsigned int realposition = 0;
Servo motor[6];
int motor_position[6]={90,90,90,90,90,90};

void setup() {
        //digitalWrite(4, HIGH);
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        //pinMode(LED_BUILTIN, OUTPUT);
        //pinMode(4, OUTPUT);
        myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(3);
  myservo5.attach(5);
  myservo6.attach(6);
       
        
}

void loop() {

        /*digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500); */
        // send data only when you receive data:
        //if (Serial.available()>0){
                //read the incoming byte:
                /*incomingByte = Serial.peek();
                incomingByte1 = Serial.peek();*/
                //incomingByte = Serial.read();
                //incomingByte = Serial.available();
        //incomingByte1 = Serial.read()
       
        // say what you got:
               //incomingByte = Serial.read();
 
               // incomingByte1 = Serial.read();
               
               
               
               // Serial.println(incomingByte);
                //Serial.println(incomingByte1);
                //Serial.println("save");
                
               /* incomingByte1 = Serial.read();
                incomingByte1 = Serial.read();*/
       
       /*else 
       {
        incomingByte = Serial.read();
        incomingByte1 = Serial.read();
       }*/
               

                
        
        /*if (Serial.available() ==2) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.println("I received: off");
                //Serial.println(incomingByte);
        }*/
         /*if(Serial.available()> 0 && Serial.read()==2)     //for reset button,serial out=2
        {
          int a=Serial.read();
          digitalWrite(4,LOW);    //reset done
          delay(100);
          digitalWrite(4,HIGH);
        }*/

        if(Serial.available()> 0 && Serial.peek()>3)
      {
        lowerBit = Serial.read();
        higherBit = Serial.read();
        realposition = (higherBit *256) + lowerBit;
        //Serial.println(realposition);
      
    
        if (realposition >= 1000 && realposition <1180) 
        {
          motor_position[0] = realposition;
          motor_position[0] = map(motor_position[0], 1000, 1180, 0, 180);
          motor[0].write(motor_position[0]);
          delay(10);
        }
        else if (realposition >= 2000 && realposition <2180) 
        {
          motor_position[1] = realposition;
          motor_position[1] = map(motor_position[1], 2000, 2180, 0, 180);
          motor[1].write(motor_position[1]);
          delay(10);
        }
        else if (realposition >= 3000 && realposition <3180) 
        {
          motor_position[2] = realposition;
          motor_position[2] = map(motor_position[2], 3000, 3180, 0, 180);
          motor[2].write(motor_position[2]);
          delay(10);
        }
        else if (realposition >= 4000 && realposition <4180) 
        {
          motor_position[3] = realposition;
          motor_position[3] = map(motor_position[3], 4000, 4180, 0, 180);
          motor[3].write(motor_position[3]);
          delay(10);
        }
        else if (realposition >= 5000 && realposition <5180)
        {
          motor_position[4] = realposition;
          motor_position[4] = map(motor_position[4], 5000, 5180, 0, 180);
          motor[4].write(motor_position[4]);
          delay(10);
        }
        else if (realposition >= 6000 && realposition <6180) 
        {
          motor_position[5] = realposition;
          motor_position[5] = map(motor_position[5], 6000, 6180, 0, 180);
          motor[5].write(motor_position[5]);
          delay(10);
        }
      }
      else
      {
        motor[0].write(motor_position[0]);
        motor[0].write(motor_position[1]);
        motor[0].write(motor_position[2]);
        motor[0].write(motor_position[3]);
        motor[0].write(motor_position[4]);
        motor[0].write(motor_position[5]); 
      }
}




syms t1 t2 t3 a1 a2 a3 d2 d3


A1=[cos(t1) -sin(t1) 0,a1*cos(t1);sin(t1) cos(t1) 0 a1*sin(t1);0 0 1 0;0 0 0 1]

A2=[cos(t2) -sin(t2) 0 a2*cos(t2);sin(t2) cos(t2) 0 a2*sin(t2);0 0 -d2 0;0 0 0 1]

A3=[cos(t3) -sin(t3) 0 a3*cos(t3);sin(t3) cos(t3) 0 a3*sin(t3);0 0 d3 0;0 0 0 1]
A1*A2*A3
