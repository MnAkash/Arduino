int led[10][7] = {
    (1,1,1,1,1,1,0),    //0
    (0,1,1,0,0,0,0),    //1
    (1,1,0,1,1,0,1),    //2
    (1,1,1,1,0,0,1),    //3
    (0,1,1,0,0,1,1),    //4
    (1,0,1,1,0,1,1),    //5
    (1,0,1,1,1,1,1),    //6
    (1,1,1,0,0,1,0),    //7
    (1,1,1,1,1,1,1),    //8
    (1,1,1,1,0,1,1)     //9
               };
int x;
int y;
int z;
void setup() 
  {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  }


void loop() 
{
  for(x=0;x<10;x++)
  {
    for(y=0;y<7;y++)
    {
    digitalWrite(y+2, led[x][y]);
    }
    delay(500);
  }
  
}
