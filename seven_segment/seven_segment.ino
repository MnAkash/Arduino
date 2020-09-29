void setup() 
{
 
int i;
void digit(int n);
for(i=7;i<=13;i++)
{
  pinMode(i,OUTPUT);
}
}

void loop() 
{
  int j;
  for(j=0;j<10;j++)
  {
    digit(j);
    delay(1000);
    }
}
void digit(int n)
{
  // {a,b,c,d,e,f,g}
  int a,p[10][7]={{1,1,1,1,1,1,0}, //0
                   {0,1,1,0,0,0,0}, //1
                   {1,1,0,1,1,0,1}, //2
                   {1,1,1,1,0,0,1}, //3
                   {0,1,1,0,0,1,1}, //4
                   {1,0,1,1,0,1,1}, //5
                   {1,0,1,1,1,1,1}, //6
                   {1,1,1,0,0,0,0}, //7
                   {1,1,1,1,1,1,1}, //8
                   {1,1,1,1,0,1,1}}; //9
  
  for(a=7;a<=13;a++)   //7-13 digital pin use korsi
  {
    digitalWrite(a,p[n][a-7]);             
  }
}
