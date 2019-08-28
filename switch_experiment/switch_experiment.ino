  int Switch = 12;
  int Switch_State = 0;
  int Switch_State_Last = 0;
  int counter = 0;
  int task=0;
  void setup() 
  {
  Serial.begin(9600);

  pinMode(Switch, INPUT);
  }

  void loop()
  {
    //int a=checkButton();

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
  Serial.println(task);
 }
    
    task=0;
  }


    
